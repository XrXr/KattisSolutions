#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    char message[101];
    message[100] = 0;

    string msg;
    getline(cin, msg);
    int r, c;
    for (int i = msg.size(); i > 0; i--) {
        if ((msg.size() % i) == 0 && (msg.size() / i) >= i) {
            r = i, c = msg.size() / i;
            break;
        }
    }

    for (int i = 0; i < msg.size(); i++) {
        int x = i / r;
        int y = i % r;
        message[y * c + x] = msg[i];
    }

    message[msg.size()] = 0;

    cout << message << endl;
}
