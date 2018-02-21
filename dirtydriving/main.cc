#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long long n, p;
    cin >> n >> p;
    vector<long long> cars;
    while(n--) {
        long long x;
        cin >> x;
        cars.push_back(x);
    }
    sort(cars.begin(), cars.end());
    long long firstDist = 0;

    for (size_t i = 0; i < cars.size(); i++) {
        long long dist = cars[i];
        long long minDist = p * (i+1);
        if (minDist > dist + firstDist) firstDist = minDist - dist;
    }
    cout << (firstDist + cars[0]) << endl;
}
