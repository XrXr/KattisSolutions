#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

struct board {
    bool state[5][5];
};

board target;
board work;
bool found;

void click(board &theboard, int y, int x) {
    theboard.state[y][x] = !theboard.state[y][x];
    theboard.state[y][x+1] = !theboard.state[y][x+1];
    theboard.state[y][x-1] = !theboard.state[y][x-1];
    theboard.state[y+1][x] = !theboard.state[y+1][x];
    theboard.state[y-1][x] = !theboard.state[y-1][x];
}

void bt(int maxdepth, int depth, board current, int fromx, int fromy) {
    bool same = true;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            if (current.state[i][j] != target.state[i][j]) {
                same = false;
                break;
            }
    if (same) {
        found = true;
        return;
    }
    if (maxdepth == depth) return;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++) {
            if (i == fromy && j == fromx) continue;
            click(current, i, j);
            bt(maxdepth, depth+1, current, j, i);
            if (found) return;
            click(current, i, j);
        }
}
//1919
int main() {
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    while(n--) {
        break;
        memset(&work, 0, sizeof(work));
        memset(&target, 0, sizeof(target));
        for (int i =1;i<=3;i++) {
            getline(cin, line);
            int j = 1;
            for (auto c : line) {
                if (c=='*') target.state[i][j]=true;
                j++;
            }
        }
        for (int i = 0; ;i++) {
            found = false;
            bt(i, 0, work, 0, 0);
            if (found) {
                cout << i << endl;
                break;
            } // 1942 resume 2000
        }
    }
    
    for (int s = 0; s <= 0b111111111; s++) {
        memset(&work, 0, sizeof(work));
        memset(&target, 0, sizeof(target));
        for (int i = 0; i < 3; i++) {
            if (s & (1 << i)) {
                target.state[1][i+1] = true;
            }
        }
        for (int i = 3; i < 6; i++) {
            if (s & (1 << i)) {
                target.state[2][i-2] = true;
            }
        }
        for (int i = 6; i < 9; i++) {
            if (s & (1 << i)) {
                target.state[3][i-5] = true;
            }
        }
        for (int i = 0; ;i++) {
            found = false;
            bt(i, 0, work, 0, 0);
            if (found) {
                cout << "table[" << s << "] = " << i << ";\n";
                break;
            }
        }
    }
}
