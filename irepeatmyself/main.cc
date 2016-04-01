#include <sstream>
#include <iostream>

using namespace std;



int main() {
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string str;
        getline(cin, str);
        int len = str.size();
        for (int i = 1; i <= str.size(); i++) {
            string sub = str.substr(0, i);
            stringstream ss;
            for (int j = 0; j < len / i; j ++) {
                ss << sub;
            }
            sub = ss.str();
            int restl = len - sub.size();
            if (sub == str.substr(0, sub.size()) &&
                str.substr(sub.size()) == sub.substr(0, restl)) {
                cout << i << endl;
                break;
            }
        }
    }
}
