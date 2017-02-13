#include <iostream> 

using namespace std;

#define HAVE 1
#define NEED 2
#define GOOD 3

int main() {
    int teams[11];
    for (int& x : teams) x = GOOD;

    int n, s, r, x;
    cin >> n >> s >> r;
    while (s--) {
        cin >> x;
        teams[x] = NEED;
    }
    while (r--) {
        cin >> x;
        if (teams[x] == NEED)
            teams[x] = GOOD;
        else
            teams[x] = HAVE;
    }
    for (int i = 1; i <= n; i++) {
        if (teams[i] != NEED) {
            continue;
        }
        if (i > 1 && teams[i-1] == HAVE) {
            teams[i] = GOOD;
            teams[i-1] = GOOD;
        } else if (i < n && teams[i+1] == HAVE) {
            teams[i] = GOOD;
            teams[i+1] = GOOD;
        }
    }
    x = 0;
    for (int i = 0; i <= n; i++) {
        if (teams[i] == NEED) x++;
    }
    cout << x << endl;
}
