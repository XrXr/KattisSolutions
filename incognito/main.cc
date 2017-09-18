#include <iostream>
#include <utility>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int nn;
        cin >> nn;
        map<string, int> count;
        while (nn--) {
            string s;
            cin >> s;
            cin >> s;
            count[s]++;
        }
        int64_t result = 1;
        for (auto val : count) {
            result *= val.second+1;
        }
        result--;
        cout << result << endl;
    }
}
