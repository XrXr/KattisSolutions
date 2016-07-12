#include <iostream>

#define MAX_HEIGHT 1000000
#define inf 0x3f3f3f3f

using namespace std;

int buildingCount[MAX_HEIGHT + 2] = {};

int main() {
    int n;
    cin >> n;

    int min = inf;
    int max = -inf;

    while (n--) {
        int tmp;
        cin >> tmp;
        buildingCount[tmp]++;
        min = tmp < min ? tmp : min;
        max = tmp > max ? tmp : max;
    }

    int maxGain = -inf;
    int maxGainAt = 0;
    int sum = 0;
    for (int i = min; i <= max; i++) {
        sum += buildingCount[i];
        int gain = sum - i;
        if (gain > maxGain && gain > 0) {
            maxGainAt = i;
            maxGain = gain;
        }
    }

    int beamCount = maxGainAt;
    for (int i = maxGainAt + 1; i <= max; i++) {
        beamCount += buildingCount[i];               
    }
    cout << beamCount << '\n';
}
