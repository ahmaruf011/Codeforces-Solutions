#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<string, int> cnt;
    while (n--) {
        string s;
        cin >> s;
        auto it = cnt.find(s);
        if (it == cnt.end()) {
            cnt[s] = 0;
            cout << "OK
";
        } else {
            it->second++;
            cout << s << it->second << "
";
        }
    }
    return 0;
}