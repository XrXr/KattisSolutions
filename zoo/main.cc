#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
int main() {
    int c = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) return 0;
        cin.ignore();

        map<string, int> counter;

        while (n--) {
            string line;
            getline(cin, line);
            stringstream parse(line);

            string word;
            while (parse >> word) {}
            
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            counter[word]++;
        }

        cout << "List " << (c++) << ":\n";
        for (auto e : counter)
            cout << e.first << " | " << e.second << '\n';
    }
}
