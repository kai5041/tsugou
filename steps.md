```
tsu init
```

check if .tsu exists
create .tsu folder and .tsu/config.json file

config.json file:
```json
{
"project_name": "<folder name>",
"tsu_version": "<tsu version>",
"date": "<unix timestamp ms>",
"scripts": {
  "e1": "echo example1",
  "e2": "ping 127.0.0.1"
}

}
```

> NOTE: you can run scripts with `tsu exec <script name>` (ex. tsu exec e1)

Enter .tsu folder, create branches and commits folders.
Each branch folder will store the final snapshot of the
project.
Each commit file in the commits folder will be named as `<branch_name>_+timestamp`.
A commit is made of 

