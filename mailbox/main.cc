#include <iostream>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

int main() {
    int dp[11][101][101];
    
    int n;
    cin >> n;

    while (n--) {
        int m, c;
        cin >> m >> c;

        for (int j = 1; j <= c; j++) {
            for (int k = 1; k <= j; k++) {
                if (j == k) {
                    dp[1][k][j] = k;
                } else {
                    dp[1][k][j] = dp[1][k][j - 1] + j;
                }
            }
        }

        for (int i = 2; i <= m; i++) {
            for (int j = 1; j <= c; j++) {
                for (int k = j; k >= 1; k--) {
                    if (j == k) {
                        dp[i][k][j] = k;
                        continue;
                    } else if (j - k == 1) {
                        dp[i][k][j] = dp[1][k][j];
                        continue;
                    }
                    int best = INF;

                    for (int l = k + 1; l <= j - 1; l++) {
                        int worstPuttingL = max(dp[i - 1][k][l - 1], dp[i][l + 1][j]) + l;
                        best = min(best, worstPuttingL);
                    }
                    dp[i][k][j] = best;
                }
            }
        }

        cout << dp[m][1][c] << endl;
    }
}
