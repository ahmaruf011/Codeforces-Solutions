#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<pair<string, int>> v;
    map<string, int> total;
 
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;
 
        v.push_back({name, score});
        total[name] += score;
    }
 
    int mx = INT_MIN;
 
    for (auto p : total) {
        mx = max(mx, p.second);
    }
 
    map<string, int> current;
 
    for (auto p : v) {
        string name = p.first;
        int score = p.second;
 
        current[name] += score;
 
        if (total[name] == mx && current[name] >= mx) {
            cout << name << endl;
            return 0;
        }
    }
 
    return 0;
}