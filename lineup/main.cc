#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> names;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        names.push_back(x);
    }
    vector<string> inc(names);
    vector<string> dec(names);

    sort(inc.begin(), inc.end());
    sort(dec.begin(), dec.end(), [](const string& a, const string& b) {
        return a > b;   
    });
    if (inc == names) {
        cout << "INCREASING\n";
    } else if (dec == names) {
        cout << "DECREASING\n";
    } else {
        cout << "NEITHER\n";
    }
}
