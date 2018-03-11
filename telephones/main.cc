#include <iostream>
#include <cstring>

using namespace std;
struct call {
    int start;
    int duration;
}calls[10001];
int main() {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m==0) break;
        
        memset(calls, 0, sizeof(calls));
        for (int i = 0; i < n; i++) {
            int dummy;
            cin >> dummy >> dummy >> calls[i].start >> calls[i].duration;
        }
        for (int i = 0; i < m; i++) {
            int count, s, d;
            count = 0;
            cin >> s >> d;
            for (int i = 0; i <n ;i++) {
                int is = calls[i].start;
                int id = calls[i].duration;
                if (is >= s && is < (s + d))
                    count ++;
                else if ((is+id-1) >= s && (is+id-1) < (s+d))
                    count ++;
                else if (s >= is && s < (is+id))
                    count ++;
            }
            cout << count << endl;
        }
    }
}
