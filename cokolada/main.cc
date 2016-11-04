#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n;
    cin >> n;
    int buy = 1;
    int shifts = 0;
    while (buy < n) buy <<= 1, shifts++;
    bitset<20> bs(n);
    int i;
    for (i = 0; i < 19; i++) {
        if (bs.test(i)) break;
    }
    cout << buy << ' ' << (shifts-i) << endl;
}
