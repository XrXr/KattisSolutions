#include <iostream>

using namespace std;
// You can expand the area in which you know the boss isn't present by
// alternating between bombing the left and the right of the current
// are in which you know the boss isn't present. Each time you do this
// the area expand by one. By the time the area is big enough you only
// need one more bomb.
int main() {
    int n; cin >>n;
    if (n <= 3) {
        cout << 1 << endl;
    } else {
        cout << (n-3+1) << endl;
    }
}
