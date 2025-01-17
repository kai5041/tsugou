from colorama import init, Fore, Style

init(autoreset=True)


def print_error(message):
    print(f"[{Fore.RED}ERROR{Fore.RESET}] {message}")
    exit(1)

def print_warning(message):
    print(f"[{Fore.YELLOW}WARNING{Fore.RESET}] {message}")
    