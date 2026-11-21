#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int s[4];
    for (int i = 0; i < 4; i++) cin >> s[i];
 
    string result = "IMPOSSIBLE";
    for (int skip = 0; skip < 4; skip++) {
        int t[3], k = 0;
        for (int i = 0; i < 4; i++)
            if (i != skip) t[k++] = s[i];
        sort(t, t + 3);
 
        if (t[0] + t[1] > t[2]) {
            result = "TRIANGLE";
            break;
        }
        if (t[0] + t[1] == t[2]) result = "SEGMENT";
    }
 
    cout << result << endl;
    return 0;
}