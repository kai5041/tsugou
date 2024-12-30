```
prm init
```

check if .prm exists
create .prm folder and .prm/config.json file

config.json file:
```json
{
"project_name": "<folder name>",
"prm_version": "<prm version>",
"date": "<unix timestamp ms>",
"scripts": {
  "e1": "echo example1",
  "e2": "ping 127.0.0.1"
}

}
```

> NOTE: you can run scripts with `prm exec <script name>` (ex. prm exec e1)

Enter .prm folder, create branches and commits folders.
Each branch folder will store the final snapshot of the
project.
Each commit file in the commits folder will be named as `<branch_name>_+timestamp`.
A commit is made of 

