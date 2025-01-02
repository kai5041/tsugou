Everything happens inside the .prm folder
Enter .prm folder

config.json file
It contains server and user related information

config.json:
```json
{
  "project_name": "",
  "project_version": "",
  "prm_version": "",
  "template": "",
  "author": "",
  "scripts": {}
}
```

branches file
Contains all the branches:
```
sha256_id name
```

commits folder
It contains all the commits as compressed folders that hold the changed files, each folder name is a sha256 hash

history file
Contains all the references to commits and branches
```
commit_hash timestamp_ms author branch_id commit_message
```

