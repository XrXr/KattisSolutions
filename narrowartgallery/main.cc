#include <iostream>
#include <algorithm>

using namespace std;
double inf = 1/.0;
double dp[3][200][201];
int val[200][2];

int main() {
    while (true) {
        int n, k;
        cin >> n >> k;
        if (n == 0 && k == 0) break;
        for(int i = 0; i < n; i++) {
            cin >> val[i][0];
            cin >> val[i][1];
        }

        fill(&dp[0][0][0], &dp[0][0][0]+3*200*201, -inf);

        dp[0][0][0] = -inf;
        dp[1][0][0] = -inf;
        dp[2][0][0] = val[0][0] + val[0][1];

        dp[0][0][1] = val[0][1];
        dp[1][0][1] = val[0][0];
        dp[2][0][1] = -inf;

        for (int i = 1; i < n; i++) {
            dp[0][i][0] = -inf;
            dp[1][i][0] = -inf;
            dp[2][i][0] = dp[2][i-1][0] + val[i][0] + val[i][1];
        }

        for (int j = 1; j < n; j++) {
            for (int i = 1; i <= j+1; i++) {
                // don't take any from this row
                int r = max(dp[0][j-1][i], max(dp[1][j-1][i], dp[2][j-1][i]));
                dp[2][j][i] = r + val[j][0] + val[j][1];

                // take left
                r = max(dp[0][j-1][i-1], dp[2][j-1][i-1]);
                dp[0][j][i] = r + val[j][1];

                // take right
                r = max(dp[1][j-1][i-1], dp[2][j-1][i-1]);
                dp[1][j][i] = r + val[j][0];
            }
        }

        cout << max(dp[0][n-1][k], max(dp[1][n-1][k], dp[2][n-1][k])) << endl;
    }
}
