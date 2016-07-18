#include <iostream>
#include <bitset>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

size_t best = INF;

void bt(const bitset<12> board) {
    bool foundMove = false;
    for (int i = 0; i < 12; i++) {
        if (board.test(i) && i + 2 < 12 && board.test(i+1) && !board.test(i+2)) {
            bitset<12> newboard(board);
            newboard.reset(i);
            newboard.reset(i+1);
            newboard.set(i+2);
            foundMove = true;
            bt(newboard);
        }

        if (board.test(i) && i - 2 >= 0 && board.test(i-1) && !board.test(i-2)) {
            bitset<12> newboard(board);
            newboard.reset(i);
            newboard.reset(i-1);
            newboard.set(i-2);
            foundMove = true;
            bt(newboard);
        }
    }

    if (!foundMove) {
        best = min(best, board.count());
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string l;
        getline(cin, l);
        
        bitset<12> board;
        int i = 0;
        for (char c : l) {
            if (c == 'o')
                board ^= 1 << i;

            i++;
        }

        best = INF;
        bt(board);
        cout << best << endl;
    }
}
