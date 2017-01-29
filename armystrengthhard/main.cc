#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int g, m;
    while (n--) {
        cin >> g >> m;
        vector<int> gg, mm;
        int x;
        while (g--) {
            cin >> x;
            gg.push_back(x);
        }
        while (m--) {
            cin >> x;
            mm.push_back(x);
        }
        sort(gg.begin(), gg.end(), greater<int>());
        sort(mm.begin(), mm.end(), greater<int>());
        g = gg.size() - 1;
        m = mm.size() - 1;
        while (g >= 0 && m >= 0) {
            int mi = min(gg[g], mm[m]);
            while (mm[m] == mi) m--;
            if (m == -1) break;
            while (gg[g] == mi) g--;
        }
        if (g == -1)
            cout << "MechaGodzilla";
        else
            cout << "Godzilla";
        cout << endl;
    }
}
