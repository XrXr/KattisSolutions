#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    unsigned long long n;
    while (cin >> n) {
        auto sum = 1ull;

        const unsigned long long stop = sqrt(n);

        for (auto i = 2ull; i <= stop; i++) {
            unsigned long long other = n / i;
            if (n % i == 0) {
                sum += i;
                if (i != other)
                    sum += other;
            }
        }
        cout << n << ' ';
        if (n == sum) {
        } else if (abs(double(sum) - double(n)) <= 2.0f)
            cout << "almost ";
        else
            cout << "not ";
        cout << "perfect" << endl;
    }
}
