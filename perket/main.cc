#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> ingredients;

    const int c = n;
    while (n--) {
        int s, b;
        cin >> s >> b;
        ingredients.emplace_back(s, b);
    }

    int minRating = 0x3f3f3f3f;
    for (int i = 1; i < (1 << c); i++) {
        int ts = 1, tb = 0;
        for (int j = 0; j < c; j++) {
            if ((i & (1 << j)) > 0) {
                auto ingre = ingredients.at(j);
                ts *= ingre.first;
                tb += ingre.second;
            }
        }
        minRating = min(minRating, abs(ts - tb));
    }
    cout << minRating << endl;
}
