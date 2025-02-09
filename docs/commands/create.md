## Syntax

```sh
$ tsu create <project_name> [<template_name>]
```


This command creates a directory named <project_name> and initializes it
as a tsu project. If a template name is supplied (optional),
the corresponding archive will be searched for in the .config/tsu/templates
folder and decompressed into the current directory.

## Example

```sh
$ tsu create HelloWorld cpp17_cmake
```


```sh
$ tree
.
└── HelloWorld/
    ├── .tsu/
    ├── CMakeLists.txt
    ├── src/
    │   └── main.cpp
    └── include/
```

