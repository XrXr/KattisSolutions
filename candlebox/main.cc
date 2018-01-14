#include <iostream>

using namespace std;

int main() {
    int d, r, t;
    cin >> d >> r >> t;
    int rage = 4;
    int tage = rage - d;
    int rc = 4;
    int tc = 0;
    for (int i = 3; i <= (rage-d);i++) {
        tc += i;
    }

    while (true) {
        if (r - rc + t == tc) {
            cout << (r-rc) << endl;
            break;
        }
        rage++;
        rc += rage;
        tage++;
        if (tage >= 3)  tc += tage;
    }
}
