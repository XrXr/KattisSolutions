#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

int main() {
    uint64_t tc, n;
    cin >> tc;

    const int score_range[] = {-1, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200};
    
    while (tc--) {
        cin >> n;
        
        uint64_t score = 0;
        
        while (n--) {
            int x, y;
            cin >> x >> y;

            double dist = sqrt(x * x + y * y);
            for (int i = 10; i >= 1; i--) {
                if ((20 * (11 - i)) >= dist) {
                    score += i;
                    break;
                }
            }
        }

        cout << score << '\n';
    }
}
