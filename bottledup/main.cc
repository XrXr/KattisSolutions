#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define inf 0x3f3f3f3f

int dp[1000001];
int back[1000001];

int main() {
    int s, a ,b;
    cin >> s >> a >> b;
    dp[0] = 0;
    back[b] = b;
    for (int i = 1; i <= b; i++)
        if (i == b)
            dp[i] = 1;
        else {
            dp[i] = inf;
            back[i] = -1;
        }

    for (int i = b+1; i <= s; i++) {
        int m = dp[i - b];
        back[i] = b;
        if (i >= a) {
            if (dp[i - a] < dp[i - b]) {
                m = dp[i - a];
                back[i] = a;
            }
        }

        if (m == inf) {
            dp[i] = inf;
            back[i] = -1;
        }
        else
            dp[i] = m + 1;
    }
    int ca = 0;
    int cb = 0;
    int cur = s;
    while (cur != 0) {
        if (back[cur] == -1) {
            cout << "Impossible\n";
            return 0;
        }
        if (back[cur] == a) {
            ca++;
            cur -= a;
        } else if (back[cur] == b) {
            cb++;
            cur -= b;
        }
    }
    cout << ca << ' ' << cb << endl;
}
