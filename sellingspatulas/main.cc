#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

#define MINUTE_MAX 1439

// dp(when, how long) = sum of profit in that range
double dp[MINUTE_MAX + 1][MINUTE_MAX + 1];
double profit[MINUTE_MAX + 1];

int main() {
    cout << fixed << setprecision(2);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int offset;
        double sale;

        double best_prof = -0x3f3f3f3f;
        int start, len;

        for (int i = 0; i < n; i++) {
            cin >> offset >> sale;
            profit[offset] = sale;
            dp[offset][1] = sale;
            if (sale - 0.08 > best_prof) {
                best_prof = sale - 0.08;
                start = offset;
                len = 1;
            }
        }


        for (int i = 2; i <= MINUTE_MAX; i++) {
            for (int j = 0; j <= (MINUTE_MAX - i + 1); j++) {
                double sum = profit[j + i - 1] + dp[j][i - 1];
                double profit_this_range = sum - i * 0.08;
                
                dp[j][i] = sum;

                if (profit_this_range > best_prof) {
                    best_prof = profit_this_range;
                    start = j;
                    len = i;
                }
            }
        }

        if (best_prof <= 0) {
            cout << "no profit" << endl;
        } else {
            cout << best_prof << ' ';
            cout << start << ' ' << start + len - 1 << endl;
        }

        memset(dp, 0, sizeof(dp));
        memset(profit, 0, sizeof(profit));
    }
}
