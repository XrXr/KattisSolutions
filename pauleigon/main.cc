#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    uint64_t n, p, q;
    cin >> n >> p >> q;
    uint64_t cur = p + q;
    if ((cur / n) & 1) {
        cout << "opponent";
    } else {
        cout << "paul";
    }
    cout << endl;
}
