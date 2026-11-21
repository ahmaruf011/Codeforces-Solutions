#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    int n = s.size();
    long long cost = 0;
    int bal = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
 
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            bal++;
        } else if (s[i] == ')') {
            bal--;
        } else {
            long long a, b;
            cin >> a >> b;
            s[i] = ')';
            cost += b;
            pq.push({a - b, i});
            bal--;
        }
        if (bal < 0) {
            if (pq.empty()) {
                cout << -1 << endl;
                return 0;
            }
            auto [d, idx] = pq.top();
            pq.pop();
            cost += d;
            s[idx] = '(';
            bal += 2;
        }
    }
 
    if (bal != 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << cost << "
" << s << endl;
    return 0;
}
 