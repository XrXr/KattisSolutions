#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int r, n;
    cin >> r >> n;

    if (r == n) {
        cout << "too late\n";
    } else {
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            s.insert(num);       
        }

        for (int i = 1; i <= r; i++) {
            if (s.find(i) == s.end()) {
                cout << i << endl;
                break;
            }
        }
    }
}
