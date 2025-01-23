import os

PRM_VERSION = "1.0.0"

current_dir = os.getcwd()

project_name = "tsu"
tsu_folder_name = "." + project_name


def join(*args):
    return os.path.join(*args)


tsu_dir = join(current_dir, tsu_folder_name)

tsu_history = join(tsu_dir, "history")
tsu_config = join(tsu_dir, "config.json")

user_config_dir = os.path.expanduser("~/.config/tsu")
