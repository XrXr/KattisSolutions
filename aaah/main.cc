#include <string>
#include <iostream>
#include <utility>

using namespace std;

int main() {
    string a,b;
    getline(cin, a);
    getline(cin, b);
    if (a.size() >= b.size()) 
        cout << "go";
    else
        cout << "no";
    cout << endl;
}
