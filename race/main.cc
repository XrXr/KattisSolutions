#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

#define inf 0x3f3f3f3f
#define MAXN 20
#define MAXT 1440

using namespace std;

struct Sol {
    vector<unordered_set<int>> used;
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

    for (int i =T; i>=0; i--) {
        const int bound = i == 0 ? n : n - 1;
        const int start = i == 0 ? n-1 : 0;
        for (int j=start; j<=bound; j++) {
            if (d[j] > -1 && i > d[j]) {
                dp[i][j].points = -inf;
                continue;
            }
            int best_points = 0;
            int best_dest = n + 1;  // n + 1 is the goal/finish location
            vector<unordered_set<int>> used; 
            
            auto attempt = [&](int k, const int best = -129) {
                if (j == k) return;
                int tk = cost[j][k] + i + t[k];  // time after completing k
                if ((d[k] > -1 && tk > d[k]) || tk > T) return;  // can't make the deadline

                auto take = dp[tk][k];
                auto points = p[k] + take.points;
                bool no_going_back = take.used.empty();
                for (auto& path : take.used) {
                    if (path.find(j) == path.end()) {
                        no_going_back = true;
                        break;
                    }
                }

                if (!no_going_back) return;

                if (best == points) {  // second iteration, fill up used
                    if (take.used.empty()) {
                        unordered_set<int> single{j};
                        used.emplace_back(move(single));
                    }
                    for (auto& path : take.used) {
                        if (path.find(j) == path.end()) {
                            unordered_set<int> copy(path);
                            copy.insert(j);
                            used.emplace_back(move(copy));
                        }
                    }
                    return;
                }

                if (points > best_points) {
                    best_dest = k;
                    best_points = points;
                }
            };

            int k;
            for (k = 0; k < n; k++) attempt(k);
            for (k = 0; k < n; k++) attempt(k, best_points);

            if (best_dest == n + 1 && cost[j][n+1] + i > T) {
                dp[i][j].points = -inf;
                continue;
            }

            if (best_dest == n + 1) {
                unordered_set<int> single{j};
                used.emplace_back(move(single));
            }

            dp[i][j].points = best_points;
            dp[i][j].used = move(used);
        }
    }

    int ttake = t[0] + cost[n][0];
    cout << dp[ ttake ][0].points << endl;  // take 0 first
    int tttake = ttake + t[1] + cost[0][1];
    cout << dp[tttake][1].points << endl;  // take 1 from there
    int ttttake = tttake + t[2] + cost[1][2];
    cout << dp[ttttake][2].points << endl;  // take 2 from there


    auto best = dp[0][n];
    if (best.points < 0) best.points = 0;
    cout << best.points << endl;

    if (best.points == 0) {
        cout << endl;
        return 0;
    }

    // now we find the solution that is lexically smallest
    //cout << "there are  " << best.used.size() << " optimal solutions" << endl;
    vector<int> best_sol(best.used.front().begin(), best.used.front().end());
    sort(best_sol.begin(), best_sol.end());
    for (auto& path : best.used) {
        vector<int> sorted(path.begin(), path.end());
        sort(sorted.begin(), sorted.end());
        if (sorted < best_sol) {
            best_sol = move(sorted);
        }
    }
    
    best_sol.pop_back();
    for (int i = 0; i < best_sol.size(); i++) {
        cout << best_sol.at(i) + 1;
        if (i != best_sol.size() - 1) cout << ' ';
    }
    cout << endl;
}
