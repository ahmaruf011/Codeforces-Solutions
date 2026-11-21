#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string line;
    int cnt = 0;
    long long total = 0;
    while (getline(cin, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;
        if (line[0] == '+') {
            cnt++;
        } else if (line[0] == '-') {
            cnt--;
        } else {
            size_t pos = line.find(':');
            total += (long long)(line.size() - pos - 1) * cnt;
        }
    }
    cout << total << endl;
    return 0;
}