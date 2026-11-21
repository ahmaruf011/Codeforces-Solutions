#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
 
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
 
    deque<int> mn, mx;
    vector<pair<int, int>> ans;
 
    int l = 0, best = 0;
 
    for (int r = 0; r < n; r++) {
 
        while (!mn.empty() && h[mn.back()] >= h[r])
            mn.pop_back();
 
        while (!mx.empty() && h[mx.back()] <= h[r])
            mx.pop_back();
 
        mn.push_back(r);
        mx.push_back(r);
 
        while (h[mx.front()] - h[mn.front()] > k) {
            if (mn.front() == l)
                mn.pop_front();
 
            if (mx.front() == l)
                mx.pop_front();
 
            l++;
        }
 
        int len = r - l + 1;
 
        if (len > best) {
            best = len;
            ans.clear();
        }
 
        if (len == best)
            ans.push_back({l + 1, r + 1});
    }
 
    cout << best << " " << ans.size() << endl;
 
    for (auto p : ans)
        cout << p.first << " " << p.second << endl;
 
    return 0;
}