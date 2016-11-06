#include <iostream>

using namespace std;

int condense(int* a, int* b, int* c, int* d) {
    int nums[4] = {*a, *b, *c, *d};
    int newnums[4] = {*a, *b, *c, *d};
    for (int i = 1; i < 4; i++) {
        int ati = nums[i];
        if (ati == 0) continue;
        for (int j = i-1; j>=0;j--) {
            int atj = nums[j];
            if(atj == 0) {
                continue;
            } else if (atj == ati) {
                nums[i] = -1;
                newnums[i] = 0;
                newnums[j] *= 2;
                break;
            } else
                break;
        }
    }

    for (int i = 1; i < 4; i++) {
        int j = i-1;
        while (j >= 0 && newnums[j] == 0) {
            newnums[j] = newnums[j+1];
            newnums[j+1] = 0;
            j--;
        }
    }
    *a = newnums[0];
    *b = newnums[1];
    *c = newnums[2];
    *d = newnums[3];
}

int main() {
    int board[4][4];
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            cin >> board[x][y];
    int command;
    cin >> command;
    if (command == 0) {
        for (int y = 0; y < 4; y++)
            condense(&board[0][y], &board[1][y], &board[2][y], &board[3][y]);
    } else if (command == 1) {
        for (int x = 0; x < 4; x++)
            condense(&board[x][0], &board[x][1], &board[x][2], &board[x][3]);
    } else if (command == 2) {
        for (int y = 0; y < 4; y++)
            condense(&board[3][y], &board[2][y], &board[1][y], &board[0][y]);
    } else {
        for (int x = 0; x < 4; x++)
            condense(&board[x][3], &board[x][2], &board[x][1], &board[x][0]);
    }

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            cout << board[x][y];
            if (x != 3) cout << ' ';
        }
        cout << endl;
    }
}
