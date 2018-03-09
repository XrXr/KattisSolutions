#include <iostream>
#include <sstream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    string sa, sb;
    stringstream ssa, ssb;
    ssa << a;
    ssb << b;
    sa = ssa.str();
    sb = ssb.str();

    string *shorter = &sa;
    string *longer = &sb;
    if (sb.size() < sa.size()) swap(shorter, longer);
    while (shorter->size() < longer->size()) {
        *shorter = ' ' + *shorter;
    }


    for (int i = 0; i < sa.size(); i++) {
        a = sa[i] - '0';
        if (i < sb.size()) {
            b = sb[i] - '0';
            if (a < b) {
                sa[i] = ' ';
            } else if (b < a) {
                sb[i] = ' ';
            }
        }
    }
    stringstream sssa, sssb;
    for (auto c : sa) if (c != ' ') sssa << c;
    for (auto c : sb) if (c != ' ') sssb << c;

    if (sssa.str().empty()) {
        cout << "YODA";
    } else {
        sssa >> a;
        cout << a;
    }
    cout << endl;
    if (sssb.str().empty()) {
        cout << "YODA";
    } else {
        sssb >> b;
        cout << b;
    }
    cout << endl;
}
