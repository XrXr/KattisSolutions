#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

struct trip {
    string s;
    int year;
};

int main () {
    int n;
    cin >> n;
    unordered_map<string, vector<int>> presort;
    while (n--) {
        string country;
        cin >> country;
        int year;
        cin >> year;
        presort[country].push_back(year);
    }
    unordered_map<string, unordered_map<int, int>> lookup;
    for (auto e : presort) {
        sort(e.second.begin(), e.second.end());
        for (int i = 0; i < e.second.size(); i++) {
            lookup[e.first][i+1] = e.second[i];
        }
    }

    cin >> n;
    while (n--) {
        string country;
        cin >> country;
        int idx;
        cin >> idx;
        cout << lookup[country][idx] << endl;
    }
}
