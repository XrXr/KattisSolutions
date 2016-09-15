#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int cn, tobuy, ones, fives, tens;

    cin >> cn;

    while (cn--) {
        cin >> tobuy >> ones >> fives >> tens;
        int a=0, b=0, c=0;
        int bought = 0;
        int coin_count = 0;
        while (bought != tobuy && tens > 0) {
            tens--;
            bought++;
            ones += 2;
            a++;
            coin_count++;
        }
        while (bought != tobuy && fives >= 2) {
            fives -= 2;
            bought++;
            b++;
            coin_count += 2;
            ones += 2;
        }
        while (bought != tobuy && fives >= 1 && ones >= 3) {
            fives--;
            bought++;
            ones -= 3;
            coin_count += 4;
        }
        while (bought != tobuy && ones >= 8) {
            ones -= 8;
            bought++;
            c++;
            coin_count += 8;
        }
        
        while (b >= 1 && c >= 1) {
            coin_count -= 2;
            c--;
            b--;
        }
        while (a >= 1 && c >= 1) {
            coin_count -= 1;
            c--;
            a--;
        }
        cout << coin_count << endl;
    }
}

