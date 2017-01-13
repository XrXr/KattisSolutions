#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> state;
    string command;
    while (cin >> command) {
        if (command == "define") {
            int val;
            string label;
            cin >> val >> label;
            //cout << val << endl;
            //cout << label << '"' << endl;
            state[label] = val;
        } else if (command == "eval") {
            string left, op, right;
            cin >> left >> op >> right;
            //printf("left: \"%s\" right: \"%s\"\n", left.data(), right.data());
            auto l = state.find(left);
            auto r = state.find(right);
            //printf("left: %d right: %d\n", *l, *r);
            if (l == state.end() || r == state.end()) {
                cout << "undefined\n";
            } else {
                int lv = l->second;
                int rv = r->second;
                bool result = (op == "=" && lv == rv) ||
                              (op == "<" && lv < rv) ||
                              (op == ">" && lv > rv);
                if (result)
                    cout << "true";
                else
                    cout << "false";
                cout << endl;
            }
        }
    }
}
