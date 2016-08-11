#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    bool first = true;
    string line;
    while(getline(cin, line)) {
        if (!first) cout << endl;
        first = false;
        vector<string> grid{line};

        while (getline(cin, line)) {
            if (line.empty()) break;
            grid.emplace_back(line);
        }

        const int h = grid.size();
        const int w = grid[0].size();

        vector<int> tab(h);

        for (int i = 0; i < grid.size(); i++) {
            for (char c : grid[i])
                if (c == '*') tab[i]++;
        }
        int push_back_so_far = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < (w - push_back_so_far) - tab[i]; j++) {
                putchar('.');
            }
            for (int j = 0; j < tab[i]; j++) putchar('*');
            for (int j = 0; j < push_back_so_far; j++) putchar('.');
            push_back_so_far += tab[i];
            
            cout << endl;
        }
    }
}
