#include <bits/stdc++.h>
using namespace std;
 
double accel(double a, double v, double dist, double v0, double &vEnd) {
    double dToMax = (v * v - v0 * v0) / (2 * a);
    if (dToMax >= dist) {
        vEnd = sqrt(v0 * v0 + 2 * a * dist);
        return (vEnd - v0) / a;
    }
    vEnd = v;
    return (v - v0) / a + (dist - dToMax) / v;
}
 
int main() {
    double a, v, l, d, w;
    cin >> a >> v >> l >> d >> w;
    double ans;
    if (w >= v || v * v / (2 * a) >= 0 && sqrt(2 * a * d) <= w) {
        double ve;
        if (w >= v) {
            ans = accel(a, v, l, 0, ve);
        } else {
            ans = accel(a, v, l, 0, ve);
        }
        printf("%.12f
", ans);
        return 0;
    }
    double vp = sqrt((2 * a * d + w * w) / 2.0);
    double t1;
    if (vp <= v) {
        t1 = vp / a + (vp - w) / a;
    } else {
        double dUp = v * v / (2 * a);
        double dDown = (v * v - w * w) / (2 * a);
        t1 = v / a + (v - w) / a + (d - dUp - dDown) / v;
    }
    double ve;
    double t2 = accel(a, v, l - d, w, ve);
    printf("%.12f
", t1 + t2);
    return 0;
}