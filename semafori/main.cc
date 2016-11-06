#include <iostream>

using namespace std;

struct light {
    bool real;
    int r;
    int g;
    bool isRed;
    int timer;
}sim[1000];

int main() {
    int n, l;
    cin >> n >> l;
    while(n--) {
        int d, r, g;
        cin >> d >> r >> g;
        sim[d].real = true;
        sim[d].isRed = true;
        sim[d].r = r;
        sim[d].g = g;
    }
    int cur = 0;
    int t= 0;
    while (cur != l) {
        if (sim[cur].real) {
            if (!sim[cur].isRed) {
                cur++;
            }
        } else {
            cur++;
        }
        for (int i = cur; i < l; i++) {
            if (sim[i].real) {
                sim[i].timer++;
                if (sim[i].isRed) {
                    if (sim[i].timer == sim[i].r) {
                        sim[i].timer = 0;
                        sim[i].isRed = !sim[i].isRed;
                    }
                } else {
                    if (sim[i].timer == sim[i].g) {
                        sim[i].timer = 0;
                        sim[i].isRed = !sim[i].isRed;
                    }
                }
            }
        }
        t++;
    }
    cout << t << endl;
}
