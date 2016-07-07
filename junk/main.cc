#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void accumulate(double& d2, double& d1, double& d0, const double s, const double sd, const double t, const double td) {
    d0 += s * s + t * t;
    d0 -= 2 * s * t;

    d1 += 2 * s * sd;
    d1 += 2 * t * td;
    d1 -= 2 * sd * t;
    d1 -= 2 * s * td;

    d2 += sd * sd;
    d2 += td * td;
    d2 -= 2 * td * sd;
}

int main() {
    int n;
    cin >> n;
    
    cout << setprecision(3) << fixed;

    for (int i = 0; i < n; i++) {
        double x0, y0, z0, r, rsum = 0, x0d, y0d, z0d,
               x1, y1, z1, x1d, y1d, z1d;

        cin >> x0 >> y0 >> z0 >> r >> x0d >> y0d >> z0d
            >> x1 >> y1 >> z1;
        rsum = r;
        cin >> r;
        rsum += r;
        cin >> x1d >> y1d >> z1d;

        double c = -(rsum * rsum), b = 0, a = 0;
        
        accumulate(a, b, c, x0, x0d, x1, x1d);
        accumulate(a, b, c, y0, y0d, y1, y1d);
        accumulate(a, b, c, z0, z0d, z1, z1d);

        double dis = (b * b) - (4 * a * c);

        double possiblePositive;
        double twoa = 2 * a;
        if (a == 0 || dis < 0) {
            cout << "No collision" << endl;
            continue;
        } else if (dis > 0) {
            double rootTerm = sqrt(dis);
            x0 = (-b + rootTerm) / twoa;
            x1 = (-b - rootTerm) / twoa;

            if (x0 > 0 && x1 > 0)
                possiblePositive = min(x0, x1);
            else 
                possiblePositive = x0 > 0 ? x0 : x1;
        } else {
            possiblePositive = -b / twoa;
        }

        if (possiblePositive < 0) {
            cout << "No collision" << endl;
        } else {
            cout << possiblePositive << endl;
        }
    }
}
