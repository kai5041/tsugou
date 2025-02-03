#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;

struct IgnoreRule {
    regex pattern;
    bool isNegation;
};

vector<IgnoreRule> parseGitignore(const string& gitignorePath) {
    vector<IgnoreRule> rules;
    ifstream file(gitignorePath);
    if (!file) {
        cerr << "Could not open " << gitignorePath << endl;
        return rules;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;  // Ignore comments and empty lines

        bool isNegation = line[0] == '!';
        if (isNegation) line = line.substr(1);  // Remove '!'

        string pattern = regex_replace(line, regex(R"(\.)"), R"(\.)");  // Escape '.'
        pattern = regex_replace(pattern, regex(R"(\*)"), R"([^/]*)");   // '*' -> match anything except '/'
        pattern = regex_replace(pattern, regex(R"(\?\)"), R"(.)");      // '?' -> match single character

        if (line.back() == '/') pattern += ".*";  // If ends with '/', match everything inside

        rules.push_back({regex("^" + pattern + "$"), isNegation});
    }
    return rules;
}

bool isIgnored(const string& filepath, const vector<IgnoreRule>& rules) {
    for (const auto& rule : rules) {
        if (regex_match(filepath, rule.pattern)) {
            return !rule.isNegation;  // Negation means it should not be ignored
        }
    }
    return false;  // Default: not ignored
}

int main() {
    string gitignorePath = ".gitignore";
    vector<IgnoreRule> rules = parseGitignore(gitignorePath);

    vector<string> files = {"logs/debug.log", "src/main.cpp", "important.log"};
    for (const auto& file : files) {
        cout << file << ": " << (isIgnored(file, rules) ? "Ignored" : "Included") << endl;
    }

    return 0;
}
