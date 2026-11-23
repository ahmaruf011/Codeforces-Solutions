#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string a[8];
    int ans = 0;
 
    for (int i = 0; i < 8; i++) {
        cin >> a[i];
    }
 
    for (int i = 0; i < 8; i++) {
        if (a[i] == "BBBBBBBB") {
            ans++;
        }
    }
 
    for (int j = 0; j < 8; j++) {
        int cnt = 0;
 
        for (int i = 0; i < 8; i++) {
            if (a[i][j] == 'B') {
                cnt++;
            }
        }
 
        if (cnt == 8) {
            ans++;
        }
    }
 
    if (ans == 16) {
        ans = 8;
    }
 
    cout << ans << endl;
 
    return 0;
}