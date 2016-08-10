#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    bool first = true;
    while (true) {
        int n;
        cin >> n;
        if (n==0) break;

        cin.ignore();

        if (!first) {
            cout << endl;
        }
        first = false;

        struct Event {
            string s;
            int n;
        };

        vector<Event> evs;
        for (int i = 0; i < n; i++) {
            string l;
            getline(cin, l);
            stringstream parse(l);


            int read, t=0, h, m;
            parse >> read;
            h = read;
            parse.ignore();
            parse >> read;
            m = read;
            parse.ignore();
            char c;
            parse >> c;
            t += (h % 12) * 60;
            if (c == 'p') t += 12 * 60;
            t += m;

            Event e = {l, t};
            evs.push_back(e);
        }
        sort(evs.begin(), evs.end(), [](const Event& a, const Event& b) {
            return a.n < b.n;  
        });

        for (auto&& e: evs) {
            cout << e.s << endl;
        }
    }
}
