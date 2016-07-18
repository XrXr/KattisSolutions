#include <iostream>
#include <vector>
#include <list>

using namespace std;

void sim(int steps, int& a, int& b) {
    a = 1;
    b = 0;

    for (int i = 0; i < steps; i++) {
        int tmp = a;
        a = b;
        b += tmp;
    }
}

int main() {
    cout << "const struct {int a, b;} answer[46] = {{}, \n";
    for (int i = 1; i <= 45; i++) {
        int a, b;
        sim(i, a, b);
        cout << "{" << a << "," << b << "}";
        if (i < 45) cout << ",\n";
    }
    cout << "};\n";
}
