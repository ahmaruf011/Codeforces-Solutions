#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> W, H, id;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > w && b > h) {
            W.push_back(a);
            H.push_back(b);
            id.push_back(i);
        }
    }
    int k = W.size();
    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> ord(k);
    for (int i = 0; i < k; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        if (W[a] != W[b]) return W[a] < W[b];
        return H[a] < H[b];
    });
    vector<int> dp(k, 1), par(k, -1);
    int best = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < i; j++) {
            if (W[ord[j]] < W[ord[i]] && H[ord[j]] < H[ord[i]] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                par[i] = j;
            }
        }
        if (dp[i] > dp[best]) best = i;
    }
    vector<int> path;
    for (int c = best; c != -1; c = par[c]) path.push_back(id[ord[c]]);
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (size_t i = 0; i < path.size(); i++) cout << path[i] << " ";
    cout << endl;
    return 0;
}