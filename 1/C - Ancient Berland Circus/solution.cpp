#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
 
int main() {
    double x[3], y[3];
    for (int i = 0; i < 3; i++) {
        if (scanf("%lf %lf", &x[i], &y[i]) != 2) return 0;
    }
    const double PI = acos(-1.0);
 
    double a = hypot(x[1] - x[2], y[1] - y[2]);
    double b = hypot(x[0] - x[2], y[0] - y[2]);
    double c = hypot(x[0] - x[1], y[0] - y[1]);
 
    double tri = fabs((x[1] - x[0]) * (y[2] - y[0]) -
                      (x[2] - x[0]) * (y[1] - y[0])) / 2.0;
    double R = a * b * c / (4.0 * tri);
 
  
    auto ang = [](double p, double q, double r) {
        double v = (q * q + r * r - p * p) / (2.0 * q * r);
        v = max(-1.0, min(1.0, v));
        return acos(v);
    };
    double A = ang(a, b, c), B = ang(b, a, c), C = ang(c, a, b);
 
    
    auto isInt = [](double v) {
        return fabs(v - floor(v + 0.5)) < 1e-4;
    };
 
    int best = 100;
    for (int n = 3; n <= 100; n++) {
        if (isInt(A * n / PI) && isInt(B * n / PI) && isInt(C * n / PI)) {
            best = n;
            break;
        }
    }
 
    double area = best / 2.0 * R * R * sin(2.0 * PI / best);
    printf("%.8f
", area);
    return 0;
}