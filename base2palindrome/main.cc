#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<unsigned long long> p = {1, 3, 5, 7};

    for (int i = 2; p.size() < n; i++) {
        for (unsigned long long j = 0; j < (1ull << i / 2); j++) {
            bitset<64> gen;
            gen.set(0);
            gen.set(i + 1);

            for (unsigned long long k = 0; k < 63; k++) {
                if ((j & (1ull << k)) > 0) {
                    gen.set(i - k);
                    gen.set(k + 1);
                }
            }

            p.push_back(gen.to_ullong());
            if (i % 2 != 0) {
                gen.set(i / 2 + 1);
                p.push_back(gen.to_ullong());
            }
        }
    }
    sort(p.begin(), p.end());
    auto result = p[n - 1];
    //cout << bitset<64>(result).to_string() << endl;
    cout << result << endl;
}
