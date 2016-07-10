#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n, c;
    cin >> n;
    c = n;

    int end[205] = { 0 };

    while(c--) {
        int l, u;
        cin >> l >> u;

        if (end[l] == 0 || end[l] > u)
            end[l] = u;
    }

    int ac = 0, buildWhen = -1;
    for (int i = 1; i <= 2 * n; i++) {
        if (end[i] > 0 && (buildWhen == -1 || end[i] < buildWhen))
            buildWhen = end[i];

        if (i == buildWhen) {
            ac++;
            buildWhen = -1;
        }
    }

    cout << ac << '\n';
}

