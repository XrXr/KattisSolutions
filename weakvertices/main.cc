#include <iostream>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == -1) break;

        bool conn[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> conn[i][j];
            }
        }
        bool outputted = false;
        for (int i = 0; i < n; i++) {
            bool weak = true;
            for (int j = 0; j < n; j++) {
                if (conn[i][j]) {
                    for (int k = 0; k < n; k++) {
                        if (conn[i][k] && k != j && conn[j][k]) {
                            weak = false;
                            break;
                        }
                    }
                }
                if (!weak) break;
            }
            if (weak) {
                if (outputted) cout << ' ';
                cout << i;
                outputted = true;
            }
        }
        cout << '\n';
    }
}

