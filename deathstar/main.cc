#include <iostream>

using namespace std;

unsigned answer[1000];

int main() {
    int n;
    cin >> n;

    unsigned x;

    for (int i = 0; i < n; i++)
        for (int j=0; j<n;j++) {
            cin >> x;
            answer[i] |= x;
            answer[j] |= x;
        }

    for (int i =0; i < n; i++) {
        if (i>0)
            cout << ' ';
        cout << answer[i];
    }
    cout << endl;
}
