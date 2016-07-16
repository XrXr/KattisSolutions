#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    uint64_t n, b;
    cin >> n >> b;

    const uint64_t shift = 1;

    cout << (n < (shift << (b + 1)) ? "yes" : "no") << endl;
}

