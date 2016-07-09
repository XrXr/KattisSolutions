#include <iostream>
#include <sstream>
#include <string>
using namespace std;

inline void convert(string& l) {
    int last = -1;
    for (char c : l) {
        int out, repeat;
        if (c == ' ') {
            out = 0;
            repeat = 1;
        } else {
            int idx = c - 'a';
            if (idx > 14) {
                int key = 7;
                key = idx > 18 ? 8 : key;
                key = idx > 21 ? 9 : key;

                int diff = 14;
                diff = idx > 18 ? 18 : diff;
                diff = idx > 21 ? 21 : diff;
    
                out = key;
                repeat = idx - diff;
            } else {
                out = idx / 3 + 2;
                repeat = idx % 3 + 1;
            }
        }

        if (out == last) cout << ' ';

        last = out;

        for (int i = 0; i < repeat; i++)
            cout << out;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i< n;i++) {
        string line;
        
        getline(cin, line);
        
        cout << "Case #" << (i+1) << ": ";
        convert(line);
        cout << '\n';
    }
}
