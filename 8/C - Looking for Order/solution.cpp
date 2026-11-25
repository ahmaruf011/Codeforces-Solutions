#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int INF = 1e9;
 
int distSq(pair<int, int> a, pair<int, int> b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx * dx + dy * dy;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int xs, ys;
    if (!(cin >> xs >> ys)) return 0;
 
    int n;
    cin >> n;
 
    vector<pair<int, int>> pts(n + 1);
    pts[0] = {xs, ys};
    for (int i = 1; i <= n; ++i) {
        cin >> pts[i].first >> pts[i].second;
    }
 
    vector<vector<int>> d(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            d[i][j] = distSq(pts[i], pts[j]);
        }
    }
 
    int max_mask = 1 << n;
    vector<int> dp(max_mask, INF);
    vector<int> parent(max_mask, -1);
 
    dp[0] = 0;
 
    for (int mask = 0; mask < max_mask; ++mask) {
        if (dp[mask] == INF) continue;
 
        int i = 0;
        while (i < n && (mask & (1 << i))) {
            ++i;
        }
        if (i == n) continue;
 
        int next_mask1 = mask | (1 << i);
        int cost1 = dp[mask] + 2 * d[0][i + 1];
        if (cost1 < dp[next_mask1]) {
            dp[next_mask1] = cost1;
            parent[next_mask1] = mask;
        }
 
        for (int j = i + 1; j < n; ++j) {
            if (!(mask & (1 << j))) {
                int next_mask2 = next_mask1 | (1 << j);
                int cost2 = dp[mask] + d[0][i + 1] + d[i + 1][j + 1] + d[j + 1][0];
                if (cost2 < dp[next_mask2]) {
                    dp[next_mask2] = cost2;
                    parent[next_mask2] = mask;
                }
            }
        }
    }
 
    cout << dp[max_mask - 1] << "
";
 
    vector<int> path;
    path.push_back(0);
    int curr = max_mask - 1;
    while (curr > 0) {
        int prev = parent[curr];
        int diff = curr ^ prev;
        for (int i = 0; i < n; ++i) {
            if (diff & (1 << i)) {
                path.push_back(i + 1);
            }
        }
        path.push_back(0);
        curr = prev;
    }
 
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i] << (i + 1 == path.size() ? "" : " ");
    }
    cout << "
";
 
    return 0;
}