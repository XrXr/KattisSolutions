#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int value(int a, int b) {
    if ((a == 1 && b == 2) || (a == 2 && b == 1)) return 300;
    if (a == b) return 200 + a;
    if (a < b)
        return value(b, a);
    else {
        stringstream ss;
        ss << a << b;
        int r;
        ss >> r;
        return r;
    }
}

int main() {
    while (true) {
        int a, b, c, d;

        cin >> a >> b >> c >> d;
        if ((a + b + c + d) == 0) break;

        if (value(a, b) == value(c, d))
            cout << "Tie.";
        else if (value(a, b) > value(c, d))
            cout << "Player 1 wins.";
        else
            cout << "Player 2 wins.";
        cout << endl;
    }
}
