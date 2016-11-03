#include <iostream>
#include <utility>
#include <bitset>
#include <cstdlib>
#include <sstream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned int n;
        cin >> n;
        int best = -1;
        stringstream ss;
        ss << n;
        string num = ss.str();
        for (int i =1 ; i <= num.size(); i++) {
            bitset<33> conv(atoi(num.substr(0, i).c_str()));
            string s = conv.to_string();
            int sum = 0;
            for (auto e : s) {
                if (e == '1') sum ++;
            }
            best = max(best, sum);
        }
        cout << best << endl;
    }
}
