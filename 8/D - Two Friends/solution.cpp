#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
 
using namespace std;
 
const double EPS = 1e-11;
 
struct Point {
    double x, y;
};
 
double dist(Point a, Point b) {
    return hypot(a.x - b.x, a.y - b.y);
}
 
Point C, H, S;
double L1, L2;
 
bool inside(Point p, Point center, double r) {
    return dist(p, center) <= r + EPS;
}
 
bool check_circles(Point p1, double r1, Point p2, double r2, Point p3, double r3) {
    if (r1 < -EPS || r2 < -EPS || r3 < -EPS) return false;
    r1 = max(0.0, r1);
    r2 = max(0.0, r2);
    r3 = max(0.0, r3);
 
    Point c[3] = {p1, p2, p3};
    double r[3] = {r1, r2, r3};
 
    for (int i = 0; i < 3; ++i) {
        if (inside(c[i], c[(i + 1) % 3], r[(i + 1) % 3]) &&
            inside(c[i], c[(i + 2) % 3], r[(i + 2) % 3])) {
            return true;
        }
    }
 
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            int k = 3 - i - j;
            double d = dist(c[i], c[j]);
            if (d > r[i] + r[j] + EPS) return false;
            if (d + min(r[i], r[j]) <= max(r[i], r[j]) + EPS) continue;
 
            double a = (r[i] * r[i] - r[j] * r[j] + d * d) / (2.0 * d);
            double h = sqrt(max(0.0, r[i] * r[i] - a * a));
 
            double x2 = c[i].x + a * (c[j].x - c[i].x) / d;
            double y2 = c[i].y + a * (c[j].y - c[i].y) / d;
 
            Point inter1 = {x2 + h * (c[j].y - c[i].y) / d, y2 - h * (c[j].x - c[i].x) / d};
            Point inter2 = {x2 - h * (c[j].y - c[i].y) / d, y2 + h * (c[j].x - c[i].x) / d};
 
            if (inside(inter1, c[k], r[k]) || inside(inter2, c[k], r[k])) {
                return true;
            }
        }
    }
 
    return false;
}
 
bool can(double d) {
    double rC = d;
    double rS = L1 - d;
    double rH = L2 - d;
    return check_circles(C, rC, S, rS, H, rH);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    double t1, t2;
    if (!(cin >> t1 >> t2)) return 0;
 
    cin >> C.x >> C.y >> H.x >> H.y >> S.x >> S.y;
 
    double dCS = dist(C, S);
    double dSH = dist(S, H);
    double dCH = dist(C, H);
 
    if (dCS + dSH <= dCH + t2 + EPS) {
        cout << fixed << setprecision(10) << min(dCS + dSH + t1, dCH + t2) << "
";
        return 0;
    }
 
    L1 = dCS + t1;
    L2 = dCH + t2;
 
    double low = 0.0, high = min(L1, L2);
    for (int iter = 0; iter < 100; ++iter) {
        double mid = (low + high) / 2.0;
        if (can(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
 
    cout << fixed << setprecision(10) << low << "
";
 
    return 0;
}