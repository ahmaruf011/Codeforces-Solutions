#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<string> lines;
    string s;
    while (getline(cin, s)) {
        if (!s.empty() && s.back() == '\r') s.pop_back();
        lines.push_back(s);
    }
    while (!lines.empty() && lines.back().empty() && false) lines.pop_back();
    size_t w = 0;
    for (auto &l : lines) w = max(w, l.size());
    cout << string(w + 2, '*') << "
";
    bool left = true;
    for (auto &l : lines) {
        size_t diff = w - l.size();
        size_t a, b;
        if (diff % 2 == 0) {
            a = b = diff / 2;
        } else {
            if (left) {
                a = diff / 2;
                b = diff - a;
            } else {
                b = diff / 2;
                a = diff - b;
            }
            left = !left;
        }
        cout << "*" << string(a, ' ') << l << string(b, ' ') << "*
";
    }
    cout << string(w + 2, '*') << "
";
    return 0;
}