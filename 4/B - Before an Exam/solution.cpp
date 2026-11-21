#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int d, sumTime;
    cin >> d >> sumTime;
    vector<int> mn(d), mx(d);
    int lo = 0, hi = 0;
    for (int i = 0; i < d; i++) {
        cin >> mn[i] >> mx[i];
        lo += mn[i];
        hi += mx[i];
    }
    if (sumTime < lo || sumTime > hi) {
        cout << "NO" << endl;
        return 0;
    }
    vector<int> res = mn;
    int rem = sumTime - lo;
    for (int i = 0; i < d && rem > 0; i++) {
        int add = min(rem, mx[i] - mn[i]);
        res[i] += add;
        rem -= add;
    }
    cout << "YES" << endl;
    for (int i = 0; i < d; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}