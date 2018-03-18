#include <iostream>

using namespace std;

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        struct {
            int number;
            int price;
            double per;
        } offers[11];
        bool good = false;
        auto best = &offers[0];
        for (int i = 0; i<n;i++) {
            cin >> offers[i].number >> offers[i].price;
            offers[i].per = static_cast<double>(offers[i].price)/static_cast<double>(offers[i].number);
            if (offers[i].number <= m) {
                good = true;
                best = &offers[i];
            }
        }
        for (int i = 0; i<n;i++) {
            //cout << offers[i].number << '!' << offers[i].price << endl;;
            if (offers[i].number > m) continue;
            if (offers[i].per < best->per || (offers[i].per == best->per && offers[i].number > best->number))
                best = &offers[i];
        }
        if (!good)
            cout << "No suitable tickets offered" <<endl;
        else
            printf("Buy %d tickets for $%d\n", best->number, best->price);
    }
}
