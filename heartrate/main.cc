#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int b;
        double p;
        cin >> b >> p;
        printf("%.4f %.4f %.4f\n", 60 / (p / (b - 1)), 60 * b / p, 60 / (p / (b + 1)));
    }
}
