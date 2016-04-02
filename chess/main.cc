#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

bool white(int x, int y) {
    return (y % 2 == 0 && x % 2 != 0) || (y % 2 != 0 && x % 2 == 0);
}

bool onboard(int x, int y) {
    return x >= 0 && x <= 7 && y >=0 && y <=7;
}

int main() {
    string xpos = "ABCDEFGH";
    int nnn;
    cin >> nnn;

    while (nnn--) {
        char e;
        cin >> e;
        int sx = xpos.find(e);
        int sy, dx, dy;
        cin >> sy >> e >> dy;
        dx = xpos.find(e);
        sy -= 1;
        dy -= 1;

        //printf("%d %d %d %d\n", sx, sy, dx, dy);

        if (sx == dx && sy == dy) {
            cout << 0 << ' ' << xpos[sx] << ' ' << sy + 1 << endl;;
            continue;
        }

        int movex = -1,
            movey = -1;

        int targetk = dy - dx,
            startk = sx + sy;

        movex = (startk - targetk) / 2;
        movey = (targetk + startk) / 2;

    
        auto notgood = [&]() {
            return (targetk - startk) % 2 != 0 || (targetk + startk) % 2 != 0 ||
                    white(sx, sy) != white(dx, dy) || !onboard(movex, movey);
        };

        if (notgood()) {
            targetk = dx + dy;
            startk = sy - sx;
            
            movex = (targetk - startk) / 2;
            movey = (targetk + startk) / 2;
            if (notgood()) {
                cout << "Impossible" << endl;
                continue;
            }
        }
        if ((movex == sx && sy == movey) || (dx == movex && dy == movey)) {
            printf("1 %c %d %c %d\n", xpos[sx], sy + 1, xpos[dx], dy + 1);
        } else {
            printf("2 %c %d %c %d %c %d\n", xpos[sx], sy + 1, xpos[movex], movey + 1, xpos[dx], dy + 1);
        }
    }
}
