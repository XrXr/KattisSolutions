#include <queue>
#include <vector>
#include <iostream>
#include <functional>
#include <cstdlib>
#include <unordered_map>
using namespace std;

void er() {
    cout << "Error" << endl;
    exit(0);
}

int main() {
    int n, orin;
    cin >> n;
    orin = n;
    int* vs = new int[n];
    int i = 0;
    while (n--) {
        cin >> vs[i++];
    }

    if (vs[i - 1] != orin + 1) er();

    priority_queue<int, vector<int>, greater<int>> heap;
    unordered_map<int, int> count;

    for (i = 0; i < orin; i++) {
        int val = vs[i];
        count[val]++;
    }

    for (i = 1; i <= orin + 1; i++) {
        if (count.find(i) == count.end()) {
            heap.push(i);
        }
    }

    for (i = 0; i < orin; i++) {
        int val = vs[i];
        cout << heap.top() << endl;
        heap.pop();
        if (--count[val] == 0) {
            heap.push(val);
        }

        if (heap.empty()) {
            //cout << "heap emptied" << endl;
            er();
        }
    }
}
