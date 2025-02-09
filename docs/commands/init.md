## Syntax

```sh
$ tsu init [<template_name>]
```

This command initializes the current directory as a tsu project. If a template name
is supplied (optional), the corresponding archive will be searched for in the
.config/tsu/templates folder and decompressed into the current directory.
If any files already exist (i.e., file collisions), the user will be
prompted to choose which file to keep.

## Example

```sh
$ tsu init cpp17_cmake
```

After running the command with the cpp17_cmake template,
the project structure will look like this.

```sh
$ tree
.
├── .tsu/
├── CMakeLists.txt
├── src/
│   └── main.cpp
└── include/
```

