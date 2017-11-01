#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

int dp[2][101][20001];
int vals[100];
int energy_levels[20001];

int main() {
    int n, cap;
    cin >> n >> cap;
    for(int i = 0; i < n; i++)
        cin>>vals[i];

    int c = cap;
    int i;
    for (i = 0;;i++) {
        energy_levels[i] = c;
        c = c * 2 / 3;
        if (c==0) break;
    }
    const int levels = i;

    for (i = n-1; i >=0; i--) {
        for (int j = 0; j <= levels; j++) {
            int cur_cap = energy_levels[j];
            int eating_reward = min(cur_cap, vals[i]);
            int level_if_rest = max(j-1, 0);
            dp[0][i][j] = max(dp[0][i+1][j+1] + eating_reward, dp[1][i+1][level_if_rest]);
            dp[1][i][j] = max(dp[0][i+1][j+1] + eating_reward, dp[1][i+1][0]);
        }
    }

    assert(dp[0][0][0] == dp[1][0][0]);

    cout << dp[0][0][0] << endl;
}
