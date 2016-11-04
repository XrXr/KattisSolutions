#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) return 0;
        cin.ignore();
        map<string,vector<string>> log;
        while (n--) {
            string line;
            getline(cin, line);
            stringstream parse(line);
            string name;
            parse >> name;
            string tok;
            while (parse >> tok) {
                log[tok].push_back(name);
            }
        }
        for (auto& e : log) {
            unique(e.second.begin(), e.second.end());
            sort(e.second.begin(), e.second.end());
            cout << e.first;
            for (auto& n : e.second) {
                cout << ' ' << n;
            }
            cout << endl;
        }
        cout << endl;
    }
}
