#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    scanf("%d", &n);
    vector<int> t(n);
    for (int i = 0; i < n; i++) scanf("%d", &t[i]);
    int l = 0, r = n - 1;
    long long ta = 0, tb = 0;
    int a = 0, b = 0;
    while (l <= r) {
        if (ta <= tb) {
            ta += t[l++];
            a++;
        } else {
            tb += t[r--];
            b++;
        }
    }
    printf("%d %d
", a, b);
    return 0;
}