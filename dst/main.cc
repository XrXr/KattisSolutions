#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char inst;
    int delta, h, m;
    while (n--) {
        cin >> inst >> delta >> h >> m;
        m = m + h * 60;
        if (inst == 'B') {
            m -= delta;
        } else {
            m += delta;
        }

        if (m < 0) {
            m = 24 * 60 + m;
        }

        cout << (m / 60) % 24 << ' ' << m % 60 << endl;
    }
}

