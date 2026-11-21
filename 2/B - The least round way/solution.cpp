#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9;
 
int n;
int a[1005][1005];
 
int cnt(int x, int p) {
    int c = 0;
 
    while (x % p == 0) {
        x /= p;
        c++;
    }
 
    return c;
}
 
pair<int, string> solve(int p) {
    vector<vector<int>> dp(n, vector<int>(n, INF));
    vector<vector<char>> par(n, vector<char>(n));
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
 
            int cost = (a[i][j] == 0) ? INF : cnt(a[i][j], p);
 
            if (i == 0 && j == 0) {
                dp[i][j] = cost;
            }
            else if (i > 0 && dp[i-1][j] < dp[i][j]) {
                dp[i][j] = dp[i-1][j] + cost;
                par[i][j] = 'D';
            }
 
            if (j > 0 && dp[i][j-1] + cost < dp[i][j]) {
                dp[i][j] = dp[i][j-1] + cost;
                par[i][j] = 'R';
            }
        }
    }
 
    string path;
    int i = n - 1, j = n - 1;
 
    while (i > 0 || j > 0) {
        char c = par[i][j];
        path += c;
 
        if (c == 'D') {
            i--;
        }
        else {
            j--;
        }
    }
 
    reverse(path.begin(), path.end());
 
    return {dp[n-1][n-1], path};
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n;
 
    int zx = -1, zy = -1;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
 
            if (a[i][j] == 0 && zx == -1) {
                zx = i;
                zy = j;
            }
        }
    }
 
    auto two = solve(2);
    auto five = solve(5);
 
    int ans = min(two.first, five.first);
 
    if (zx != -1 && ans > 1) {
        cout << 1 << '
';
 
        for (int i = 0; i < zx; i++) cout << 'D';
        for (int j = 0; j < zy; j++) cout << 'R';
 
        for (int i = zx; i < n - 1; i++) cout << 'D';
        for (int j = zy; j < n - 1; j++) cout << 'R';
 
        cout << '
';
    }
    else if (two.first < five.first) {
        cout << two.first << '
';
        cout << two.second << '
';
    }
    else {
        cout << five.first << '
';
        cout << five.second << '
';
    }
 
    return 0;
}