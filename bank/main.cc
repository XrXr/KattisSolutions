#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct {
    int val;
    bool have;
} dp[10001][49];

struct Cust {
    int val;
    int t;
};

int n, t;
// i is number of customers processed so far
int solve(int i, int current_time, const vector<Cust> &customers) {
    auto &memo = dp[i][current_time];
    if (memo.have) return memo.val;
    
    if (i >= customers.size()) return 0;
    if (current_time >= t) return 0; // bank's closed

    int best = solve(i+1, current_time, customers);
    Cust this_customer = customers[i];
    if (current_time <= this_customer.t) {
        best = max(best, solve(i+1, current_time+1, customers) + this_customer.val);
    }

    memo.have = true;
    memo.val = best;
    return memo.val;
}

int main() {
    cin >> n >> t;
    vector<Cust> customers;
    for (int i =0; i<n;i++){
        int ci, ti;
        cin >> ci >> ti;
        Cust c;
        c.val = ci;
        c.t = ti;
        customers.push_back(c);
    }

    sort(customers.begin(), customers.end(), [](const Cust &a, const Cust &b) {
        return a.t < b.t;
    });

    cout << solve(0, 0, customers) << endl;

}
