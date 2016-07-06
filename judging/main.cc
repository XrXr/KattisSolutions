#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> f, s;
    for (int i = 0; i < n; i++) {
        string l;
        cin >> l;
        f[l]++;
    }
    for (int i = 0; i < n; i++) {
        string l;
        cin >> l;
        s[l]++;
    }
    int sum = 0;
    for (auto e : f) {
        int second_count = s[e.first];
        sum += e.second <= second_count ? e.second : second_count;
    }
    cout << sum << '\n';
}
