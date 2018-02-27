#include <iostream>
#include <string>

using namespace std;

bool same(char a, char b, char c) {
    return a == b && b == c && a == c;
}

bool diff(char a, char b, char c) {
    return a != b && a != c && b != c;
}

int main() {
    string cards[12];
    for (int i = 0;i < 12; i++) {
        cin >> cards[i]; 
    }
    bool any = false;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            for (int k = 0; k < 12; k++) {
                if (i >= j || j >= k) continue;
                bool pass = true;
                for (int l = 0; l < 4; l++)
                    pass = pass && (same(cards[i][l], cards[j][l], cards[k][l]) || diff(cards[i][l], cards[j][l], cards[k][l]));
                if (pass) {
                    printf("%d %d %d\n", i+1, j+1, k+1);
                    any = true;
                }
            }
    if (!any) cout << "no sets" << endl;
}
