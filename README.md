# Tsugou / 都合 | A lightweight Project Builder and Version Control System

## Installation

###  0.0.1 "Kai Burned Out Edition" (WINDOWS 11 ONLY)
**Windows 11 x86_64**   
Open Powershell and enter the following command:
```powershell
$bin="$HOME\bin"; if(-not(Test-Path $bin)){New-Item -ItemType Directory -Path $bin|Out-Null}; if(-not($env:PATH -split ";"|?{$_ -eq $bin})){[Environment]::SetEnvironmentVariable("PATH",$env:PATH+";"+$bin,"User")}; Invoke-WebRequest "https://github.com/kai5041/tsugou/releases/download/0.0.1-kboe/tsu.exe" -OutFile (Join-Path $bin "tsu.exe")
```

**Linux 11 x86_64**  
Open the terminal and enter the following command:
```bash
sudo curl -L "https://github.com/kai5041/tsugou/releases/download/0.0.1-kboe/tsu" -o /usr/local/bin/tsu && sudo chmod +x /usr/local/bin/tsu
```

Close the shell and open it. Enjoy your `tsu` command.

## Usage
```sh
$ tsu "<CXX_COMPILER>" "<SOURCE_DIR>" "<OUT_FILENAME>" "[<CXX_FLAGS>]" "[CXX_LD_FLAGS]"
```

## License
This project is licensed under the [MIT License](/LICENSE).

## Contact
Visit [HARMONY連's website](https://harmonyren.net/contact-us) for contact options.
