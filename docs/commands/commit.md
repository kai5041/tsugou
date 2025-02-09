## Syntax

```sh
$ tsu commit "<message>" [algo]
```

This command pushes the changes under the current branch found in `.tsu/config.json`,
the commit is signed with an algorithm of your choice and is written to the `.tsu/history` file.
If no algorithm is specified, the default algorithm used is `ed25519`.
Each commit follows this format:

```
commit_hash timestamp_ms 'message' branch user_id algorithm:public_key signature
```

## Example

### `.tsu/config.json`
```json
{
  ...
  "user_id": "123e4567-e89b-12d3-a456-426614174000",
  "branch": "master",
  ...
  }
```

```sh
$ tsu commit "Added a new feature"
```

The tool will search in `.tsu/ed25519` for the private key, load it and sign the commit.

The history file under `.tsu/history` will look like this:
```
08b27ed202062bd95d2f5df77184ab928876b278074e870da11adbee25478454 1739012892 'Added a new feature' master 123e4567-e89b-12d3-a456-426614174000 ed25519:AAAAC3NzaC1lZDI1NTE5AAAAIAm07vcmIPxeoys37GaveDwEc5PdblD5mGmmOfxAe4rU 2d2d2d2d2d424547494e20535348205349474e41545552452d2d2d2d2d0a55314e4955306c48414141414151414141444d414141414c63334e6f4c57566b4d6a55314d546b414141416743625475397959672f46366a4b7a66735a7139345041527a6b390a317555506d59616159352f45423769745141414141496447567a64433530654851414141414141414141426e4e6f595455784d67414141464d414141414c63334e6f4c57566b0a4d6a55314d546b4141414241697a335737634349414d6c4a6f4d4d33335846796f624876363430437358436e566a454d706761525670435452664e677a3664584c676c516d450a7a50626b483445697575393654506949444442474a69584a684e43513d3d0a2d2d2d2d2d454e4420535348205349474e41545552452d2d2d2d2d0a

```