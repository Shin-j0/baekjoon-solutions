# staged 파일 없으면 자동 add
if (-not (git diff --cached --name-only)) {
    git add cpp/src
}

$file = git diff --cached --name-only | Select-Object -First 1

if (-not $file) {
    Write-Host "No files to commit"
    exit 1
}

if ($file -match '(\d+)') {
    $boj = $matches[1]
} else {
    $boj = "unknown"
}

$ext = [System.IO.Path]::GetExtension($file)

$lang = switch ($ext) {
    ".cpp" { "C++" }
    ".py"  { "Python" }
    ".java" { "Java" }
    default { "Code" }
}

git commit -m "solve: BOJ $boj ($lang)"
