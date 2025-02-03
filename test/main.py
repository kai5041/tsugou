import os
import re

def parse_gitignore(path):
    rules = []
    unignore_rules = []

    with open(path, "r") as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("#"):  # Ignore comments and empty lines
                continue

            is_negation = line.startswith("!")
            pattern = line[1:] if is_negation else line

            # Convert .gitignore pattern to regex
            pattern = pattern.replace(".", r"\.").replace("*", "[^/]*").replace("?", ".")
            if pattern.endswith("/"):  # Directory match
                pattern += ".*"
            regex = re.compile(f"^{pattern}$")

            if is_negation:
                unignore_rules.append(regex)
            else:
                rules.append(regex)

    return rules, unignore_rules

def is_ignored(filepath, rules, unignore_rules):
    for rule in unignore_rules:
        if rule.match(filepath):
            return False  # Unignored
    for rule in rules:
        if rule.match(filepath):
            return True  # Ignored
    return False  # Not ignored

# Example usage
rules, unignore_rules = parse_gitignore(".gitignore")

files = ["logs/debug.log", "src/main.c", "important.log"]
for file in files:
    print(f"{file}: {'Ignored' if is_ignored(file, rules, unignore_rules) else 'Included'}")
