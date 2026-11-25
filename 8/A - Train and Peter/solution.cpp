#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
bool can_see(const string& path, const string& first, const string& second) {
    size_t idx1 = path.find(first);
    if (idx1 == string::npos) {
        return false;
    }
    size_t idx2 = path.find(second, idx1 + first.length());
    return idx2 != string::npos;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s, a, b;
    if (!(cin >> s >> a >> b)) {
        return 0;
    }
 
    bool fwd = can_see(s, a, b);
 
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    bool bwd = can_see(rev_s, a, b);
 
    if (fwd && bwd) {
        cout << "both
";
    } else if (fwd) {
        cout << "forward
";
    } else if (bwd) {
        cout << "backward
";
    } else {
        cout << "fantasy
";
    }
 
    return 0;
}