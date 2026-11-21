#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
 
static bool isRC(const char *s) {
   
    if (s[0] != 'R' || !(s[1] >= '0' && s[1] <= '9')) return false;
    int i = 1;
    while (s[i] >= '0' && s[i] <= '9') i++;
    return s[i] == 'C' && s[i + 1] >= '0' && s[i + 1] <= '9';
}
 
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    char buf[64];
    string out;
    while (n-- > 0 && scanf("%63s", buf) == 1) {
        if (isRC(buf)) {
           
            int i = 1;
            string row;
            while (buf[i] != 'C') row += buf[i++];
            long long col = atoll(buf + i + 1);
            string letters;
            while (col > 0) {
                col--;
                letters += char('A' + col % 26);
                col /= 26;
            }
            reverse(letters.begin(), letters.end());
            out += letters + row + "
";
        } else {
           
            int i = 0;
            long long col = 0;
            while (buf[i] >= 'A' && buf[i] <= 'Z') {
                col = col * 26 + (buf[i] - 'A' + 1);
                i++;
            }
            out += "R" + string(buf + i) + "C" + to_string(col) + "
";
        }
    }
    fputs(out.c_str(), stdout);
    return 0;
}
 