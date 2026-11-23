#include <iostream>
 
using namespace std;
 
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    long long A, B, C;
    if (!(cin >> A >> B >> C)) return 0;
 
    long long x0, y0;
    long long g = extended_gcd(A, B, x0, y0);
 
    if ((-C) % g != 0) {
        cout << -1 << "
";
        return 0;
    }
 
    __int128 factor = (-C) / g;
    long long x = (long long)((__int128)x0 * factor);
    long long y = (long long)((__int128)y0 * factor);
 
    cout << x << " " << y << "
";
 
    return 0;
}