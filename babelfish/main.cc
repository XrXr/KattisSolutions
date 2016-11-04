#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {
    string line;
    unordered_map<string, string> dict;
    while (getline(cin, line)) {
        if (line == "") break;

        stringstream ss(line);
        string e, o;
        ss >> e >> o;
        dict[o] = e;        
    }

    while (getline(cin, line)) {
        string word = line.substr(0, line.size());
        auto re = dict.find(word);
        if (re == dict.end()) {
            cout << "eh" << endl;
        } else {
            cout << (re->second) << endl;
        }
    }
}
