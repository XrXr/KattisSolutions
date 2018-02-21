#include <iostream>
#include <string>
using namespace std;

int main() {
    int guess;
    string one;
    string two;
    int lower = 1;
    int upper = 10;
    while (true) {
        cin >> guess;
        //cout << "guess is " << guess << endl;
        if (guess == 0) break;
        cin >> one >> two;
        if (two == "on") {
            if (guess < lower || guess > upper) {
                cout << "Stan is dishonest\n";
            } else {
                cout << "Stan may be honest\n";
            }
            lower = 1;
            upper = 10;
            continue;
        }
        if (two == "low" && (guess + 1) > lower) lower = guess + 1;
        if (two == "high" && (guess - 1) < upper) upper = guess - 1;
        //cout << "low is " << lower  << " upper is " << upper<< endl;
    }
}
