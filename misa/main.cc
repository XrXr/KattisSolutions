#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <tuple>
using namespace std;

void shake(vector<vector<bool>> &grid, set<tuple<int, int, int, int>> &record, int oy, int ox, int y, int x) {
    if (grid.at(oy).at(ox)) {
        pair<int, int> to, from;
        from.first = x;
        from.second = y;
        to.first = ox;
        to.second = oy;
        if (from < to) swap(to, from);
        record.insert(make_tuple(to.first, to.second, from.first, from.second));
    }
}

int main() {
    int r, s;
    cin >> r >> s;

    string line;
    getline(cin, line); // eat extra

    vector<vector<bool>> grid;
    grid.push_back(vector<bool>(s + 2, false));

    for (int i = 0; i < r; i++) {
        getline(cin, line);

        vector<bool> row;
        row.push_back(false);
        for (int i = 0; i < s; i++) {
            row.push_back(line[i] == 'o');
        }
        row.push_back(false);
        grid.push_back(row);
    }
    grid.push_back(vector<bool>(s + 2, false));
    
    int maxNeighbor = -1;
    int bestRow;
    int bestSeat;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= s; j++) {
            //cout << grid[i][j] << endl;
            if (grid[i][j] == false) {
                int instNeighbor = 0;
                instNeighbor += grid[i][j+1];
                instNeighbor += grid[i][j-1];
                instNeighbor += grid[i+1][j];
                instNeighbor += grid[i+1][j+1];
                instNeighbor += grid[i+1][j-1];
                instNeighbor += grid[i-1][j];
                instNeighbor += grid[i-1][j+1];
                instNeighbor += grid[i-1][j-1];
                if (instNeighbor > maxNeighbor) {
                    bestRow = i;
                    bestSeat = j;
                    maxNeighbor = instNeighbor;
                }
            }
        }
    if (maxNeighbor != -1) {
        //cout << "haha" << bestRow << bestSeat << endl;
        grid[bestRow][bestSeat] = true;
    }

    set<tuple<int, int, int, int>> record;
    for (int i = 1; i <= r; i ++)
        for (int j = 1; j <= s; j++) {
            if (!grid[i][j]) continue;
            shake(grid, record, i, j+1, i, j);
            shake(grid, record, i, j-1, i, j);
            shake(grid, record, i+1, j, i, j);
            shake(grid, record, i+1, j+1, i, j);
            shake(grid, record, i+1, j-1, i, j);
            shake(grid, record, i-1, j, i, j);
            shake(grid, record, i-1, j+1, i, j);
            shake(grid, record, i-1, j-1, i, j);
        }
    cout << record.size() << endl;
}
