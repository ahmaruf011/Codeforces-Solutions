#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t, m;
    cin >> t >> m;
 
    int a[105] = {0};
    int id = 0;
 
    while (t--) {
        string s;
        cin >> s;
 
        if (s == "alloc") {
            int n;
            cin >> n;
 
            int cnt = 0, pos = -1;
 
            for (int i = 0; i < m; i++) {
                if (a[i] == 0)
                    cnt++;
                else
                    cnt = 0;
 
                if (cnt == n) {
                    pos = i - n + 1;
                    break;
                }
            }
 
            if (pos == -1) {
                cout << "NULL
";
            } else {
                id++;
                for (int i = pos; i < pos + n; i++) {
                    a[i] = id;
                }
                cout << id << "
";
            }
        }
 
        else if (s == "erase") {
            int x;
            cin >> x;
 
            bool found = false;
 
            for (int i = 0; i < m; i++) {
                if (a[i] == x && x > 0) {
                    a[i] = 0;
                    found = true;
                }
            }
 
            if (!found) {
                cout << "ILLEGAL_ERASE_ARGUMENT
";
            }
        }
 
        else if (s == "defragment") {
            int j = 0;
 
            for (int i = 0; i < m; i++) {
                if (a[i] != 0) {
                    a[j] = a[i];
                    j++;
                }
            }
 
            while (j < m) {
                a[j] = 0;
                j++;
            }
        }
    }
 
    return 0;
}