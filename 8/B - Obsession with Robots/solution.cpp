#include <iostream>
#include <string>
#include <vector>
#include <cmath>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s;
    if (!(cin >> s)) {
        return 0;
    }
 
    int n = static_cast<int>(s.size());
    vector<pair<int, int>> pos(n + 1);
    pos[0] = {0, 0};
 
    for (int i = 0; i < n; ++i) {
        int x = pos[i].first;
        int y = pos[i].second;
        if (s[i] == 'L') --x;
        else if (s[i] == 'R') ++x;
        else if (s[i] == 'U') ++y;
        else if (s[i] == 'D') --y;
        pos[i + 1] = {x, y};
    }
 
    for (int i = 0; i <= n; ++i) {
        for (int j = i + 2; j <= n; ++j) {
            int dist = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
            if (dist <= 1) {
                cout << "BUG
";
                return 0;
            }
        }
    }
 
    cout << "OK
";
    return 0;
}