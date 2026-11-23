#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s;
    if (!(cin >> s)) return 0;
 
    int n = s.length();
    vector<int> dp(n + 1, 0);
 
    const unsigned long long P = 131;
    unsigned long long forward_hash = 0;
    unsigned long long reverse_hash = 0;
    unsigned long long power_p = 1;
    long long total_degree_sum = 0;
 
    for (int i = 1; i <= n; ++i) {
        unsigned long long char_val = static_cast<unsigned long long>(s[i - 1]);
        forward_hash = forward_hash * P + char_val;
        reverse_hash = reverse_hash + char_val * power_p;
        power_p *= P;
 
        if (forward_hash == reverse_hash) {
            dp[i] = dp[i / 2] + 1;
            total_degree_sum += dp[i];
        }
    }
 
    cout << total_degree_sum << "
";
 
    return 0;
}