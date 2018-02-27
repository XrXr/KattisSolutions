#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> count;
    for (int i = 0 ; i < n; i++) {
        int courses[6];
        cin >> courses[0] >> courses[1]>> courses[2] >> courses[3] >> courses[4];
        sort(courses, courses+5);
        stringstream ss;
        for (int j = 0 ; j < 5; j++) ss << courses[j];

        count[ss.str()]++;       
    }
    int best = 0;
    for (auto e : count)
        best = max(e.second, best);
    int total= 0;
    for (auto e : count) {
        if (e.second == best) total += best;
    }
    cout << total << endl;
}
