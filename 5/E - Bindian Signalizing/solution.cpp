#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    scanf("%d", &n);
    vector<int> h(n);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    int mi = max_element(h.begin(), h.end()) - h.begin();
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = h[(mi + i) % n];
    vector<pair<int, long long>> st;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long c = 1;
        while (!st.empty() && st.back().first < a[i]) {
            ans += st.back().second;
            st.pop_back();
        }
        if (!st.empty() && st.back().first == a[i]) {
            ans += st.back().second;
            c = st.back().second + 1;
            st.pop_back();
            if (!st.empty()) ans++;
        } else if (!st.empty()) {
            ans++;
        }
        st.push_back({a[i], c});
    }
    while (st.size() > 2) {
        ans += st.back().second;
        st.pop_back();
    }
    if (st.size() == 2 && st[0].second > 1) ans += st[1].second;
    cout << ans << endl;
    return 0;
}