#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[101][30001];
int price[100];
struct {
    int a, b, item;
} back[101][30001];

int main() {
    int n;
    cin >> n;
    for(int i =0;i<n;i++) cin >> price[i];

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    
    for (int i = 1; i <=n; i++) {
        int p = price[i-1];
        for (int j = 0; j <= 30000; j++) {
            int s = dp[i-1][j];
            if (j >= p) s += dp[i][j-p];

            if (s >= 2) {
                dp[i][j] = 2;
            } else {
                dp[i][j] = s;
                if (s == 1) {
                    if(dp[i-1][j]) {
                        back[i][j].a = i-1;
                        back[i][j].b = j;
                    } else {
                        back[i][j].a = i;
                        back[i][j].b = j-p;
                        back[i][j].item = i;
                    }
                }
            }
        }
    }
    
    int nq;
    cin >> nq;
    while(nq--){
        int q;
        cin >> q;

        if (dp[n][q] == 0) {
            cout << "Impossible";
        } else if (dp[n][q] == 2) {
            cout << "Ambiguous";
        } else {
            int a = n;
            int b = q;
            vector<int> items;
            while (b != 0) {
                auto &prev = back[a][b];
                if (prev.item != 0)
                    items.push_back(prev.item);
                a = prev.a;
                b = prev.b;
            }
            sort(items.begin(), items.end());
            bool first = true;
            for (auto e : items) {
                if (!first) cout << ' ';
                cout << e;
                first = false;
            }
        }
        cout << endl;
    }
}
