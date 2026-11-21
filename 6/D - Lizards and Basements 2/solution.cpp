#include <bits/stdc++.h>
using namespace std;
 
int n, a, b;
int h[15], cnt[15], ans[15];
int best = INT_MAX;
 
void dfs(int i, int total) {
    if (total >= best) return;
 
    if (i == n - 1) {
        if (h[n - 1] - cnt[n - 2] * b >= 0)
            return;
 
        best = total;
 
        for (int j = 1; j < n - 1; j++)
            ans[j] = cnt[j];
 
        return;
    }
 
    int damage = 0;
 
    if (i >= 2)
        damage += cnt[i - 2] * b;
 
    damage += cnt[i - 1] * a;
 
    int rem = h[i - 1] - damage;
 
    int k = 0;
 
    if (rem >= 0)
        k = rem / b + 1;
 
    for (int x = k; x <= 16; x++) {
        cnt[i] = x;
        dfs(i + 1, total + x);
    }
 
    cnt[i] = 0;
}
 
int main() {
    cin >> n >> a >> b;
 
    for (int i = 0; i < n; i++)
        cin >> h[i];
 
    dfs(1, 0);
 
    cout << best << endl;
 
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < ans[i]; j++)
            cout << i + 1 << " ";
    }
 
    cout << endl;
 
    return 0;
}