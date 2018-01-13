#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int cubes[80];
int combcount[400001];

int main() {
    int n;
    cin >> n;
    
    int acc = 0;
    int i;
    for (i = 1; acc < 400000; i++) {
        acc = i * i * i;
        cubes[i-1] = acc;
    }
    const int nCubes = i-1;
    vector<int> busNums;
    for (int i = 0; i < nCubes; i++) {
        for (int j = i; j < nCubes; j++) {
            if (i == j) continue;
            int cubeSum = cubes[i] + cubes[j];
            if (cubeSum <= 400000 && combcount[cubeSum] < 2) {
                combcount[cubeSum]++;
                if (combcount[cubeSum] >= 2) {
                    busNums.push_back(cubeSum);
                }
            } 
        }
    }

    sort(busNums.begin(), busNums.end());

    bool found = false;
    for (auto it = busNums.rbegin(); it != busNums.rend(); it++) {
        if (*it <= n) {
            cout << *it << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "none\n";
}   
