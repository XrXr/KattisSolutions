#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, d, e, f, width, height;

bool trial(int tx, int ty, int& ox, int& oy) {
    int count = 0;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++) {
            int x = tx + i * width;
            int y = ty + j * height;
            if ((x == a || x == c || x == e) && (y == b || y == d || y == f) &&
                !((x == a && y == b) || (x == c && y == d) || (x == e && y == f))) {
                ox = x;
                oy = y;
                return true;
            }
        }
    return false;
}

int main() {
    cin >> a >> b >> c >> d >> e >> f;

    width = max(max(abs(c - a), abs(e - c)), abs(e - a));
    height = max(max(abs(b - d), abs(b - f)), abs(d - f));

    int x = -1, y = -1;

    trial(a, b, x, y) || trial(c, d, x, y) || trial(e, f, x, y);

    cout << x << ' ' << y << endl;
}
