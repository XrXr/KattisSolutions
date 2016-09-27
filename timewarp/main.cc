#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string tok;
        int angle, hour;
        cin >> angle >> tok >> hour;

        hour %= 12;
        double sa = 360 - (hour / 12.0 * 360.0);
        if (sa == 360) sa = 0;

        double da;
        if (tok == "after") {
            if (angle <= sa)
                da = 360 - sa + angle;
            else
                da = angle - sa;
        } else {
            if (angle >= sa)
                da = sa + 360 - angle;
            else
                da = sa - angle;
            da = -da;
        }

        // the change of angle between arms every second
        const double ca = (360.0 / (60 * 60)) - (360.0 / (12 * 60 * 60));

        int th = round(da / ca) + hour * 60 * 60;
        const int nsec = 12 * 60 * 60;
        th = (th % nsec + nsec) % nsec;

        int h = th / 3600;
        th = th % 3600;
        int m = th / 60;
        int s = th % 60;

        if (h == 0) h = 12;

        printf("Case %d: %d:%02d:%02d\n", i+1, h, m, s);
    }
}
