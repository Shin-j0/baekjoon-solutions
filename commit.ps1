# commit.ps1 - group changes by BOJ problem number and commit per problem (SAFE)
$ErrorActionPreference = "Stop"

# 변경 파일 목록 (추적 + 미추적, 삭제 제외)
$changed = git status --porcelain | Where-Object {
    $_ -notmatch '^D '
} | ForEach-Object {
    $_.Substring(3).Trim()
} | Where-Object { $_ -ne "" }

if (-not $changed -or $changed.Count -eq 0) {
    Write-Host "No changes to commit."
    exit 0
}

function Get-BojNumber([string]$path) {
    $p = $path -replace '\\','/'   # normalize

    if ($p -match '(^|/)cpp(/src)?/(\d+)\.cpp$')       { return $matches[3] }
    if ($p -match '(^|/)python(/src)?/(\d+)\.py$')     { return $matches[3] }
    if ($p -match '(^|/)java(/src)?/(\d+)/.+\.java$')  { return $matches[3] }

    return $null
}

function Get-Lang([string[]]$paths) {
    # 확장자 기준 1순위
    if ($paths | Where-Object { $_ -match '\.cpp$' })  { return "C++" }
    if ($paths | Where-Object { $_ -match '\.java$' }) { return "Java" }
    if ($paths | Where-Object { $_ -match '\.py$' })   { return "Python" }

    # 보조: 경로 기준
    if ($paths | Where-Object { $_ -match '(^|[\\/])cpp([\\/]|$)' })    { return "C++" }
    if ($paths | Where-Object { $_ -match '(^|[\\/])java([\\/]|$)' })   { return "Java" }
    if ($paths | Where-Object { $_ -match '(^|[\\/])python([\\/]|$)' }) { return "Python" }

    return "Code"
}

$groups = @{}

foreach ($f in $changed) {
    $boj = Get-BojNumber $f
    if (-not $boj) { continue }

    if (-not $groups.ContainsKey($boj)) {
        $groups[$boj] = New-Object System.Collections.Generic.List[string]
    }
    $groups[$boj].Add($f)
}

if ($groups.Count -eq 0) {
    Write-Host "No BOJ-numbered files found to commit."
    exit 0
}

foreach ($boj in ($groups.Keys | Sort-Object {[int]$_})) {
    $files = $groups[$boj] | Sort-Object -Unique

    foreach ($file in $files) {
        git add -- $file
    }

    if (-not (git diff --cached --name-only)) { continue }

    $lang = Get-Lang $files
    git commit -m "solve: BOJ $boj ($lang)"
    Write-Host "✅ Committed: BOJ $boj ($lang)"
}

Write-Host "Done. Run 'git push' when ready."
