#include <iostream>
#include <cmath>
#include <string>
#include <utility>

using namespace std;

int main() {
    int h;
    cin >> h;
    string path;
    cin.ignore();
    getline(cin, path);
    long long level = 1;
    long long skip = 0;
    long long x = 0;
    for (char c: path) {
        if (c == 'L') {
            x = x * 2 + 1;
            level++;
        } else if (c == 'R') {
            x = x * 2;
            level++;
        }
    }
    long long number = 0;
    for (int i = level; i <= h; i++) {
        number += pow(2, i);
    }
    cout << (number + x + 1) << endl;
}
