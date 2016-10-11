#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string in;
    cin >> in;
    string best = in;
    
    for (int i = 1; i < (in.size() - 1); i++)
        for (int j = i+1; j < in.size(); j++) {
            string tr = in;
            reverse(tr.begin(), tr.begin() + i);
            reverse(tr.begin() + i, tr.begin() + j);
            reverse(tr.begin() + j, tr.end());
            if (tr < best) best = move(tr);
        }

    cout << best << '\n';
}
