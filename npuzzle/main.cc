#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int grid[16];
    for (int i = 0; i < 16; i++) {
        char c;
        cin >> c;
        grid[i] = c;
    }

    int scatter = 0;
    for (int i = 0; i < 16; i++) {
        if (grid[i] == '.') continue;
        int orix = (grid[i] - 'A') % 4;
        int oriy = (grid[i] - 'A') / 4;
        int x = i % 4;
        int y = i / 4;
        
        scatter += abs(orix - x) + abs(oriy - y);
    }

    cout << scatter << '\n';
}
