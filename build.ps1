# Directories
$srcDir = "src"
$buildDir = "build"
$objDir = Join-Path $buildDir "obj"
$outputExe = Join-Path $buildDir "tsu.exe"

# Compilation flags
$flags = "-Wall -Wextra -O2 -std=c++17 -Iinclude"

# Ensure build directories exist
foreach ($dir in @($buildDir, $objDir)) {
    if (-not (Test-Path $dir)) {
        New-Item -ItemType Directory -Path $dir | Out-Null
    }
}

# Get all .cpp files
$cppFiles = Get-ChildItem -Path $srcDir -Filter *.cpp

if ($cppFiles.Count -eq 0) {
    Write-Error "No .cpp files found in $srcDir"
    exit 1
}

$recompiled = @()

# Compile each .cpp into .o if needed
foreach ($file in $cppFiles) {
    $objFile = Join-Path $objDir ($file.BaseName + ".o")
    
    # Check if recompilation is needed
    if (-not (Test-Path $objFile) -or $file.LastWriteTime -gt (Get-Item $objFile).LastWriteTime) {
        $compileCmd = "g++ -c $flags `"$($file.FullName)`" -o `"$objFile`""
        Write-Output $compileCmd
        Invoke-Expression $compileCmd
        if ($LASTEXITCODE -ne 0) {
            exit 1
        }
        $recompiled += $file.Name
    }
}

# Link all .o files
$objFilesArray = Get-ChildItem -Path $objDir -Filter *.o | ForEach-Object { "`"$($_.FullName)`"" }
$objFiles = $objFilesArray -join " "
$linkCmd = "g++ $objFiles -o `"$outputExe`""
Invoke-Expression $linkCmd

if ($LASTEXITCODE -ne 0) {
    Write-Error "Linking failed."
}
