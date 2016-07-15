#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

int main () {
    string currentProject;
    unordered_map<string, unordered_set<string>> count;
    unordered_map<string, string> signedUp;
    while (true) {
        string line;
        int d;
        if (cin >> d) {
            cin.ignore();
            if (d == 1) {
                typedef pair<string, unordered_set<string>> MapT;
                vector<MapT> total(count.begin(), count.end());

                sort(total.begin(), total.end(), [](const MapT& a, const MapT& b) {
                    auto asize = a.second.size();
                    auto bsize = b.second.size();

                    if (asize == bsize) return a.first < b.first;
                    return asize > bsize;
                });
                signedUp.clear();
                count.clear();
                for (auto&& e : total) cout << e.first << ' ' << e.second.size() << endl;
                continue;
            }
            break;
        }
        cin.clear();

        getline(cin, line);
        if (toupper(line[0]) == line[0]) {
            currentProject = move(line);
            count[currentProject];
        } else {
            auto anotherProject = signedUp.find(line);
            if (anotherProject != signedUp.end() && anotherProject->second != currentProject) {
                count.find(anotherProject->second)->second.erase(line);
                continue;
            }
            signedUp[line] = currentProject;
            count[currentProject].insert(line);
        }
    }
}

