# Tsugou / 都合 | A lightweight Project Builder and Version Control System

## Installation

###  0.0.0 "Kai Burned Out Edition"
**Windows 11 x86_64**: Open Powershell and enter the following command:
```powershell
$bin="$HOME\bin"; if(-not(Test-Path $bin)){New-Item -ItemType Directory -Path $bin|Out-Null}; if(-not($env:PATH -split ";"|?{$_ -eq $bin})){[Environment]::SetEnvironmentVariable("PATH",$env:PATH+";"+$bin,"User")}; Invoke-WebRequest "https://github.com/kai5041/tsugou/releases/download/0.0.0-KBOE/tsu.exe" -OutFile (Join-Path $bin "tsu.exe")
```

## License
This project is licensed under the [MIT License](/LICENSE).

## Contact
Visit [HARMONY連's website](https://harmonyren.net/contact-us) for contact options.
