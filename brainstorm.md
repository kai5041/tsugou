The user initializes a prm repo:
```
$ prm init
```

A `.prm` folder is created, where the branches and commits are stored.
Branches and commits are folders, each commit named as a unix timestamp in seconds is a snapshot of the branch.
A branch is formed of multiple commits.
Each commit folder has a `commit` file, which contains the author's info and commit message.


Add files to the repo:
```
$ prm add [files]
```

The default branch created is `master`, this can be customized given `prm.json`.
If files or folders are specified, they are added to the current branch.
Else, prm will add all files in the current directory.
.gitignore can be used to ignore files that should not be added to the repo.

This will push the current branch to the remote repository, the server.
```
$ prm push [msg]
```


This will pull/update the current branch from the remote repository, the server.
```
$ prm update
```

To switch to an existing branch:
```
$ prm switch <branch>
```
If the branch doesn't exist, a new one has to be created with `prm add` modifying the `branch` in prm.json.

