#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>
 
using namespace std;
 
enum Type {
    ATOM,
    MUL,
    ADD,
    BAD
};
 
struct MacroInfo {
    Type type;
    bool safe;
};
 
map<string, MacroInfo> macros;
 
struct Parser {
    string s;
    int pos;
 
    Parser(const string& str) : s(str), pos(0) {}
 
    void skipSpaces() {
        while (pos < (int)s.length() && isspace(s[pos])) {
            pos++;
        }
    }
 
    pair<Type, bool> parseExpr() {
        auto left = parseTerm();
        while (true) {
            skipSpaces();
            if (pos < (int)s.length() && (s[pos] == '+' || s[pos] == '-')) {
                char op = s[pos++];
                auto right = parseTerm();
                if (!left.second || !right.second) {
                    left = {BAD, false};
                } else if (op == '-' && right.first == ADD) {
                    left = {BAD, false};
                } else {
                    left = {ADD, true};
                }
            } else {
                break;
            }
        }
        return left;
    }
 
    pair<Type, bool> parseTerm() {
        auto left = parseFactor();
        while (true) {
            skipSpaces();
            if (pos < (int)s.length() && (s[pos] == '*' || s[pos] == '/')) {
                char op = s[pos++];
                auto right = parseFactor();
                if (!left.second || !right.second) {
                    left = {BAD, false};
                } else if (left.first == ADD || right.first == ADD) {
                    left = {BAD, false};
                } else if (op == '/' && right.first == MUL) {
                    left = {BAD, false};
                } else {
                    left = {MUL, true};
                }
            } else {
                break;
            }
        }
        return left;
    }
 
    pair<Type, bool> parseFactor() {
        skipSpaces();
        if (pos < (int)s.length() && s[pos] == '(') {
            pos++;
            auto res = parseExpr();
            skipSpaces();
            if (pos < (int)s.length() && s[pos] == ')') {
                pos++;
            }
            if (!res.second) return {BAD, false};
            return {ATOM, true};
        } else if (pos < (int)s.length() && isalpha(s[pos])) {
            string name;
            while (pos < (int)s.length() && isalpha(s[pos])) {
                name += s[pos++];
            }
            if (macros.count(name)) {
                return {macros[name].type, macros[name].safe};
            }
            return {ATOM, true};
        } else {
            while (pos < (int)s.length() && isdigit(s[pos])) {
                pos++;
            }
            return {ATOM, true};
        }
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    if (!(cin >> n)) return 0;
    string line;
    getline(cin, line);
 
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        int idx = 0;
        while (idx < (int)line.length() && isspace(line[idx])) idx++;
        if (idx < (int)line.length() && line[idx] == '#') idx++;
        while (idx < (int)line.length() && isspace(line[idx])) idx++;
        idx += 6;
        while (idx < (int)line.length() && isspace(line[idx])) idx++;
 
        string name;
        while (idx < (int)line.length() && isalpha(line[idx])) {
            name += line[idx++];
        }
        string expr = line.substr(idx);
 
        Parser p(expr);
        auto res = p.parseExpr();
        macros[name] = {res.first, res.second};
    }
 
    getline(cin, line);
    Parser p(line);
    auto ans = p.parseExpr();
 
    if (ans.second) {
        cout << "OK
";
    } else {
        cout << "Suspicious
";
    }
 
    return 0;
}