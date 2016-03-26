#include <iostream>
#include <algorithm>
#include <vector>

#define inf 0x3f3f3f3f
#define MAXN 20
#define MAXT 1440

using namespace std;

struct Sol {
    vector<int> used;
    int points;
    int t;

    Sol() : points(0), t(0) {}
} dp[MAXT+2][MAXN+2];
int p[MAXN + 2];
int t[MAXT + 2];
int d[MAXN + 2];
int cost[MAXN+2][MAXN+2];

int main() {
    int n, T;

    cin >> n >> T;
    for (int i =0; i< n; i++)
        cin >> p[i] >> t[i] >> d[i];
    
    
    for (int i =0; i< n+2; i++)
        for (int j =0; j< n+2; j++)
            cin >> cost[i][j];

    d[n] = -1;
    t[n] = 0;
    p[n] = 0;
    d[n+1] = -1;
    p[n+1] = 0;
    t[n+1] = 0;

    for (int i =T; i>=0; i--)
        for (int j=0; j<=n; j++) {
            int best_points = 0;
            int best_dest = n + 1;  // n + 1 is the goal/finish location
            int best_lex_dis = inf;
            
            auto attempt = [&](int& k) {
                if (j == k) return;
                int tk = cost[j][k] + i + t[k];  // time after completing k
                if ((d[k] > -1 && tk > d[k]) || tk > T) return;  // can't make the deadline
                auto take = dp[tk][k];

                auto enditer = take.used.end();
                auto points = p[k] + take.points;
                int lex = take.used.empty() ? inf : take.used.back() - j;
                if ((points > best_points || (points == best_points && lex > 0 && lex < best_lex_dis)) &&
                        take.t + tk - i < T &&
                        find(take.used.begin(), enditer, j) == enditer) {  // best path in that item doesn't involve j
                    best_dest = k;
                    best_points = points;
                    best_lex_dis = lex;
                }
                return;
            };

            int k;
            for (k = n - 1; k >= 0; k--) attempt(k);
            //for (k = j + 1; k < n; k++) attempt(k);

            if (best_dest == n + 1 && cost[j][n+1] + i > T) {
                dp[i][j].points = -inf;
                continue;
            }

            auto tk = cost[j][best_dest] + i + t[best_dest];
            auto take = dp[tk][best_dest];
            dp[i][j].points = p[best_dest] + take.points;
            dp[i][j].used = take.used;
            dp[i][j].used.push_back(j);
            dp[i][j].t = take.t + tk - i;
        }

    auto best = dp[0][n];
    if (best.points < 0) best.points = 0;
    cout << best.points << endl;

    if (best.points == 0) {
        cout << endl;
        return 0;
    }

    // now we find the solution that is lexically smallest
    sort(best.used.begin(), best.used.end());
    const auto bpoint = best.points;
    vector<int>* best_sol = &best.used;
    for (int i = 0; i < n; i++) {
        auto tk = cost[n][i] + t[i];
        if (bpoint == p[i] + dp[tk][i].points) {  // a solution just as good
            sort(dp[tk][i].used.begin(), dp[tk][i].used.end());
            dp[tk][i].used.push_back(n);
            if (dp[tk][i].used < *best_sol) best_sol = &dp[tk][i].used;
        }
    }
    
    best_sol->pop_back();
    for (int i = 0; i < best_sol->size(); i++) {
        cout << best_sol->at(i) + 1;
        if (i != best_sol->size() - 1) cout << ' ';
    }
    cout << endl;
}
