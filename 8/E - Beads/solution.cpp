#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int n;
ll k;
string s;
 
ll dp[51][3][3][2];
 
ll solve(int i, int a, int b, int c) {
    int j = n - i - 1;
 
    if (i > j)
        return a != 2 && b != 2 && c;
 
    ll &res = dp[i][a][b][c];
 
    if (res != -1)
        return res;
 
    res = 0;
 
    for (int x = 0; x <= 1; x++) {
        for (int y = 0; y <= 1; y++) {
            if (i == j && x != y) continue;
            if (i == 0 && x != 0) continue;
 
            if (s[i] != '?' && s[i] - '0' != x) continue;
            if (s[j] != '?' && s[j] - '0' != y) continue;
 
            int na = a, nb = b;
 
            if (a == 0 && x != y)
                na = x < y ? 1 : 2;
 
            if (b == 0 && x != 1 - y)
                nb = x < 1 - y ? 1 : 2;
 
            res += solve(i + 1, na, nb, c || x || y);
        }
    }
 
    return res;
}
 
ll countWays() {
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, 0, 0);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> k;
 
    s = string(n, '?');
 
    if (countWays() < k) {
        cout << -1 << '
';
        return 0;
    }
 
    for (int i = 0; i < n; i++) {
        s[i] = '0';
 
        ll cnt = countWays();
 
        if (cnt < k) {
            k -= cnt;
            s[i] = '1';
        }
    }
 
    cout << s << '
';
 
    return 0;
}