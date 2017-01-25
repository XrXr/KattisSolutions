#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool prime(int x) {
    for (int i = 2; i <= int(sqrt(x)); i++) {
        if ((x % i) == 0) return false;
    }
    return true;
}

int main() {
    vector<int> primes;
    for (int i = 2; i <= 32000; i++) {
        if (prime(i)) primes.push_back(i);
    }
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        vector<pair<int,int>> matches;
        for (int i = 0; i < primes.size(); i++) {
            int p = primes[i];
            if (p >= x) break;
            int lookfor = x - p;
            bool found = binary_search(primes.begin() + i, primes.end(), lookfor);
            if (found) {
                matches.emplace_back(make_pair(p, lookfor));
            }
        }
        printf("%d has %d representation(s)\n", x, int(matches.size()));
        for (auto& e : matches)
            cout << e.first << '+' << e.second << endl;
        cout << endl;
    }
}

