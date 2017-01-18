#include <iostream>
#include <cmath>
#include <list>

using namespace std;

int main() {
    int cap;
    cin >> cap;
    cin.ignore();
    string line;
    getline(cin, line);
    list<bool> queue;
    for (char e : line)
        queue.push_back(e == 'M');

    int diff = 0;
    int count = 0;
    while (!queue.empty()) {
        int pending = 1 + -2 * queue.front();
        int second;
        if (queue.size() == 1 || (abs(pending + diff) < abs((second = 1 + -2 * *(++queue.begin())) + diff))) {
            queue.pop_front();
            diff += pending;
        } else {
            queue.erase(++queue.begin());
            diff += second;
        }
        if (abs(diff) > cap)
            break;
        else
            count++;
    }
    cout << count << '\n';
}
