# commit.ps1 - group changes by BOJ number and commit per problem
$ErrorActionPreference = "Stop"

# 1) 변경 파일 목록 (추적/미추적 포함)
$changed = git status --porcelain | ForEach-Object {
    $_.Substring(3).Trim()
} | Where-Object { $_ -ne "" }

if (-not $changed -or $changed.Count -eq 0) {
    Write-Host "No changes to commit."
    exit 0
}

# 2) BOJ 번호 추출 함수
function Get-BojNumber([string]$path) {
    if ($path -match '(\d+)') { return $matches[1] }
    return $null
}

# 3) 언어 판별(폴더/확장자 기준)
function Get-Lang([string[]]$paths) {
    $exts = $paths | ForEach-Object { [System.IO.Path]::GetExtension($_).ToLower() } | Sort-Object -Unique
    $langs = @()

    foreach ($e in $exts) {
        switch ($e) {
            ".py"   { $langs += "Python" }
            ".java" { $langs += "Java" }
            ".cpp"  { $langs += "C++" }
            default {
                # 확장자 없거나 txt 등은 "Code"로 두되,
                # 경로에 python/java/cpp가 있으면 그쪽으로 맞춰줌
                if ($paths -match '(^|[\\/])python([\\/]|$)') { $langs += "Python" }
                elseif ($paths -match '(^|[\\/])java([\\/]|$)') { $langs += "Java" }
                elseif ($paths -match '(^|[\\/])cpp([\\/]|$)') { $langs += "C++" }
                else { $langs += "Code" }
            }
        }
    }

    $langs = $langs | Sort-Object -Unique
    if ($langs.Count -eq 1) { return $langs[0] }
    return "Mixed"
}

# 4) (BOJ 번호) 기준으로 그룹핑
$groups = @{}
foreach ($f in $changed) {
    $boj = Get-BojNumber $f
    if (-not $boj) { continue }
    if (-not $groups.ContainsKey($boj)) { $groups[$boj] = New-Object System.Collections.Generic.List[string] }
    $groups[$boj].Add($f)
}

if ($groups.Count -eq 0) {
    Write-Host "No BOJ-numbered files found to commit."
    exit 0
}

# 5) 번호 순서대로 커밋
$bojs = $groups.Keys | Sort-Object {[int]$_}

foreach ($boj in $bojs) {
    $files = $groups[$boj] | Sort-Object -Unique

    # 파일들 add
    foreach ($file in $files) {
        git add -- $file
    }

    # 스테이징된 게 없으면 스킵
    $staged = git diff --cached --name-only
    if (-not $staged) { continue }

    $lang = Get-Lang $files
    $msg = "solve: BOJ $boj ($lang)"

    git commit -m "$msg"
    Write-Host "✅ Committed: $msg"
}

Write-Host "Done. (Run 'git push' once if you want.)"
