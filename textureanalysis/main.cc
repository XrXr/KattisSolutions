#include <iostream>
#include <string>

using namespace std;

int main() {
    int cn = 1;
    while (true) {
        string line;
        getline(cin, line);
        if (line == "END") break;
        
        auto e = ++(line.begin());
        int whiteCount = 0;
        for (; e != line.end(); e++, whiteCount++) {
            if (*e == '*') break;
        }
        if (e != line.end()) e++;

        bool even = true;
        int currentCount = 0;
        while (e != line.end()) {
            if (*e == '*') {
                if (currentCount != whiteCount) {
                    even = false;
                    break;
                } else {
                    currentCount = 0;
                }
            } else {
                currentCount++;
            }
            e++;
        }

        cout << cn++ << ' ' <<  (even ? "EVEN" : "NOT EVEN") << '\n';
    }
}
