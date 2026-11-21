#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s, t;
    cin >> s >> t;
 
    int x = t[0] - s[0];
    int y = t[1] - s[1];
 
    cout << max(abs(x), abs(y)) << '
';
 
    while (x != 0 || y != 0) {
        string ans = "";
 
        if (x > 0) {
            ans += 'R';
            x--;
        }
        else if (x < 0) {
            ans += 'L';
            x++;
        }
 
        if (y > 0) {
            ans += 'U';
            y--;
        }
        else if (y < 0) {
            ans += 'D';
            y++;
        }
 
        cout << ans << '
';
    }
 
    return 0;
}