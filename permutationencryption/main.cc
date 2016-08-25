#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;

        vector<int> keys;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            keys.push_back(k-1);
        }
        cin.ignore();

        string line;
        getline(cin, line);
        if (line.size() % n) {
            int deficit =  (n - (line.size() % n));
            for (int i = 0; i < deficit; i++) {
                line += ' ';
            }
        }

        auto iter = line.begin();
        while (iter != line.end()) {
            string reordered(n, ' ');
            for (int i = 0; i < n; i++) {
                char access = iter[keys[i]];
                reordered[i] = access;
            }
            for (int i = 0; i < n; i++) {
                iter[i] = reordered[i];
            }
            iter += n;
        }
        cout << "'" << line << "'" << endl;
    }
}
