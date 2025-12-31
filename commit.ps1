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

function Get-Lang([string[]]$paths) {
    # 확장자 기준이 1순위 (가장 정확)
    if ($paths | Where-Object { $_ -match '\.cpp$' })  { return "C++" }
    if ($paths | Where-Object { $_ -match '\.java$' }) { return "Java" }
    if ($paths | Where-Object { $_ -match '\.py$' })   { return "Python" }

    # 보조: 경로 기준
    if ($paths | Where-Object { $_ -match '(^|[\\/])cpp([\\/]|$)' })    { return "C++" }
    if ($paths | Where-Object { $_ -match '(^|[\\/])java([\\/]|$)' })   { return "Java" }
    if ($paths | Where-Object { $_ -match '(^|[\\/])python([\\/]|$)' }) { return "Python" }

    return "Code"
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
