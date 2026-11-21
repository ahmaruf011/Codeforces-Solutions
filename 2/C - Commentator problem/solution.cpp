#include <bits/stdc++.h>
using namespace std;
 
using ld = long double;
 
struct Point {
    ld x, y;
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    Point c[3];
    ld r[3];
 
    for (int i = 0; i < 3; i++) {
        cin >> c[i].x >> c[i].y >> r[i];
    }
 
    ld a = 2 * (c[0].x - c[1].x);
    ld b = 2 * (c[0].y - c[1].y);
    ld d = 2 * (c[0].x - c[2].x);
    ld e = 2 * (c[0].y - c[2].y);
 
    ld det = a * e - b * d;
 
    ld s1 = c[1].x * c[1].x + c[1].y * c[1].y
          - c[0].x * c[0].x - c[0].y * c[0].y;
 
    ld s2 = c[2].x * c[2].x + c[2].y * c[2].y
          - c[0].x * c[0].x - c[0].y * c[0].y;
 
    ld t1 = r[1] * r[1] - r[0] * r[0];
    ld t2 = r[2] * r[2] - r[0] * r[0];
 
    Point P0, P1;
 
    P0.x = (-s1 * e + b * s2) / det;
    P0.y = (-a * s2 + d * s1) / det;
 
    P1.x = (t1 * e - b * t2) / det;
    P1.y = (a * t2 - d * t1) / det;
 
    ld ux = P0.x - c[0].x;
    ld uy = P0.y - c[0].y;
 
    ld A = P1.x * P1.x + P1.y * P1.y;
    ld B = 2 * (ux * P1.x + uy * P1.y)
         - r[0] * r[0];
    ld C = ux * ux + uy * uy;
 
    vector<ld> roots;
    const ld EPS = 1e-12;
 
    if (fabsl(A) < EPS) {
        if (fabsl(B) > EPS) {
            roots.push_back(-C / B);
        }
    } else {
        ld D = B * B - 4 * A * C;
 
        if (D >= -EPS) {
            D = max((ld)0, D);
            ld sq = sqrtl(D);
 
            roots.push_back((-B - sq) / (2 * A));
            roots.push_back((-B + sq) / (2 * A));
        }
    }
 
    ld best = 1e30;
    Point ans;
 
    for (ld t : roots) {
        if (t < 1 - EPS) continue;
 
        t = max((ld)1, t);
 
        Point p;
        p.x = P0.x + P1.x * t;
        p.y = P0.y + P1.y * t;
 
        if (t < best) {
            best = t;
            ans = p;
        }
    }
 
    if (best == 1e30) return 0;
 
    cout << fixed << setprecision(5);
    cout << ans.x << " " << ans.y << '
';
 
    return 0;
}