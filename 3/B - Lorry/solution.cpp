#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, v;
    cin >> n >> v;
 
    vector<pair<int, int>> a, b;
 
    for (int i = 1; i <= n; i++) {
        int t, p;
        cin >> t >> p;
 
        if (t == 1)
            a.push_back({p, i});
        else
            b.push_back({p, i});
    }
 
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
 
    vector<long long> pre1(a.size() + 1, 0);
    vector<long long> pre2(b.size() + 1, 0);
 
    for (int i = 0; i < (int)a.size(); i++)
        pre1[i + 1] = pre1[i] + a[i].first;
 
    for (int i = 0; i < (int)b.size(); i++)
        pre2[i + 1] = pre2[i] + b[i].first;
 
    long long best = 0;
    int x = 0, y = 0;
 
    for (int i = 0; i <= min(v, (int)a.size()); i++) {
        int j = min((v - i) / 2, (int)b.size());
 
        long long sum = pre1[i] + pre2[j];
 
        if (sum > best) {
            best = sum;
            x = i;
            y = j;
        }
    }
 
    cout << best << '
';
 
    for (int i = 0; i < x; i++)
        cout << a[i].second << " ";
 
    for (int i = 0; i < y; i++)
        cout << b[i].second << " ";
 
    cout << '
';
 
    return 0;
}