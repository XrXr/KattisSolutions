#include <iostream>
#include <cstdint>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        for (int i = 0; i < line.size() - 1; i++) {
            if (line[i] == '0' && tolower(line[i+1]) == 'x') {
                int j;
                for (j = 0; j < 8; j++) {
                    char c = line[i+2+j];
                    if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
                        break;
                    }
                }
                if (j > 0) {
                    string num = line.substr(i, j+2);
                    stringstream parse(num);
                    uint64_t n;
                    parse >> hex >> n;
                    cout << num << ' ' << n << '\n';
                }
            }
        }
    }
}
