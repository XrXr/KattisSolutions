#include <iostream>

using namespace std;

int main () {
    int n;
    cin >> n;
    while (n--) {
        int iq[2000];
        int ncs, ne;
        cin >> ncs >> ne;
        
        for (int i = 0; i < ncs + ne; i++) {
            cin >> iq[i];
        }

        double etotal = 0;
        for (int i = ncs; i < ncs + ne; i++) {
            etotal += iq[i];
        }

        double cstotal = 0;
        for (int i = 0; i < ncs; i++) {
            cstotal += iq[i];
        }

        const double ae = static_cast<double>(etotal) / ne;
        const double acs = cstotal / ncs;
        int answer = 0;
        for (int i = 0; i < ncs; i++) {
            if (((iq[i] + etotal) / (ne+1)) > ae && (cstotal - iq[i]) / (ncs-1) > acs) {
                answer++;
            }
        }

        cout << answer << endl;
    }
}
