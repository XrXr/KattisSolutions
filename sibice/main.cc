#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, w, h;

    cin >> n >> w >> h;

    double hype = hypot(w, h);

    while (n--) {
        int x;
        cin >> x;

        if (x <= hype) {
            cout << "DA";
        } else {
            cout << "NE";
        }
        cout << endl;
    }
}
