#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    char c;
    cin >> n >> m >> c;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    set<char> s;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != c) continue;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 || y < 0 || x >= n || y >= m) continue;
                if (g[x][y] != '.' && g[x][y] != c) s.insert(g[x][y]);
            }
        }
    }
    cout << s.size() << endl;
    return 0;
}