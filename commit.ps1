# commit.ps1 - group changes by BOJ problem number (SAFE VERSION)
$ErrorActionPreference = "Stop"

# 변경 파일 목록 (추적 + 미추적, 삭제 제외)
$changed = git status --porcelain | Where-Object {
    $_ -notmatch '^D '
} | ForEach-Object {
    $_.Substring(3).Trim()
}

if (-not $changed) {
    Write-Host "No changes to commit."
    exit 0
}

function Get-BojNumber([string]$path) {
    # python/src/1697.py
    if ($path -match 'python[\\/].*[\\/](\d+)\.py') { return $matches[1] }

    # cpp/src/10026.cpp
    if ($path -match 'cpp[\\/].*[\\/](\d+)\.cpp') { return $matches[1] }

    # java/src/1504/Main.java
    if ($path -match 'java[\\/].*[\\/](\d+)[\\/].*\.java') { return $matches[1] }

    return $null
}

function Get-Lang([string]$path) {
    if ($path -match 'python') { return "Python" }
    if ($path -match 'cpp')    { return "C++" }
    if ($path -match 'java')   { return "Java" }
    return "Code"
}

# BOJ 번호별 그룹
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

    $lang = Get-Lang $files[0]
    git commit -m "solve: BOJ $boj ($lang)"
    Write-Host "✅ Committed: BOJ $boj ($lang)"
}

Write-Host "Done. Run 'git push' when ready."
