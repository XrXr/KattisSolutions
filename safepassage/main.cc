#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int speed[20];
int dp[0x8000][2];
bool have[0x8000][2];
int all = 0;

long long solve(int board, bool cloak_at_gate) {
    if (have[board][cloak_at_gate]) {
        return dp[board][cloak_at_gate];
    }
    if (board == 0) return 0;
    if (cloak_at_gate) {
        vector<int> cand;
        for (int i = 0 ; i < 15; i++) {
            if ((board & (1<<i)) > 0) {
                cand.push_back(i);
            }
        }

        if (cand.size() == 2) {
            return max(speed[cand[0]], speed[cand[1]]);
        }

        long long best = 0x3f3f3f3f;
        for (int i = 0 ; i < cand.size() - 1; i ++)
            for (int j = i+1; j < cand.size(); j++) {
                int nb = board;
                nb &= ~(1 << cand[i]);
                nb &= ~(1 << cand[j]);
                int this_cost = max(speed[cand[i]], speed[cand[j]]);

                best = min(best, solve(nb, !cloak_at_gate) + this_cost);
            }

        have[board][cloak_at_gate] = true;
        dp[board][cloak_at_gate] = best;
        return best;
    } else {
        vector<int> cand;
        int dorm = (~board) & all;
        for (int i = 0 ; i < 15; i++) {
            if ((dorm & (1<<i)) > 0) {
                cand.push_back(i);
            }
        }

        long long best = 0x3f3f3f3f;
        for (int i = 0 ; i < cand.size(); i ++) {
            int nb = board;
            nb |= 1 << cand[i];

            best = min(best, solve(nb, !cloak_at_gate) + speed[cand[i]]);
        }

        have[board][cloak_at_gate] = true;
        dp[board][cloak_at_gate] = best;
        return best;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> speed[i];
        all |= 1 << i;
    }
    cout << solve(all, true) << endl;
}
