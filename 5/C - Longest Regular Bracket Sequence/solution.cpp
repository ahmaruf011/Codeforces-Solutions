#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n + 1, 0);
    int best = 0, cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == ')') {
            int j = i - 1 - dp[i - 1] - 1;
            if (j >= 0 && s[j] == '(') {
                dp[i] = dp[i - 1] + 2 + dp[j];
                if (dp[i] > best) {
                    best = dp[i];
                    cnt = 1;
                } else if (dp[i] == best) {
                    cnt++;
                }
            }
        }
    }
    if (best == 0) {
        cout << "0 1" << endl;
    } else {
        cout << best << " " << cnt << endl;
    }
    return 0;
}