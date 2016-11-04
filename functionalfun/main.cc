#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream parse{line};
        string tok;
        parse >> tok;
        unordered_set<string> domain;
        while (parse >> tok) {
            domain.insert(tok);
        }
        getline(cin, line);
        parse = stringstream(line);
        parse >> tok;
        unordered_set<string> codomain;
        while (parse >> tok) {
            codomain.insert(tok);
        }
        unordered_map<string, string> mapping;
        int n;
        cin >> n;
        string x, y;
        bool onetoone = true,
             onto = false,
             func = true;
        while (n--) {
            cin >> x >> tok >> y;
            auto f = mapping.find(x);
            if (f != mapping.end() && f->second != y) {
                func = false;
            }
            mapping[x] = y;
        }
        cin.ignore();

        if (func) {
            unordered_set<string> mappedto;
            for (auto e : mapping) {
                if (mappedto.find(e.second) != mappedto.end()) onetoone = false;
                mappedto.insert(e.second);
            }
            if (mappedto == codomain) {
                onto = true;
            }
        }

        if (!func)
            cout << "not a function";
        else if (onetoone && onto)
            cout << "bijective";
        else if (onetoone)
            cout << "injective";
        else if (onto)
            cout << "surjective";
        else
            cout << "neither injective nor surjective";
        cout << endl;
    }
}
