from .utils import Fore

from datetime import datetime


class Commit:
    def __init__(self, id: str, message: str, author: str, timestamp: str, files: list):
        self.id = id
        self.message = message
        self.author = author
        self.timestamp = timestamp
        self.files = files

    def __str__(self):
        return self.__dict__.__str__()

    def show(self):
        print(f"Hash id: {self.id}")
        print(f"Message: {self.message}")
        print(f"Author: {self.author}")
        print(f"Timestamp: {datetime.fromtimestamp(int(self.timestamp))}")

        for file in self.files:
            print("[", end="")
            match file[0]:
                case "A":
                    print(f"{Fore.GREEN}+", end="")
                case "D":
                    print(f"{Fore.RED}-", end="")
                case "M":
                    print(f"{Fore.CYAN}|", end="")

            file = file[1:]

            print(f"{Fore.RESET}] {file}")
