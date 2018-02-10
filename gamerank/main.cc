#include <iostream>
#include <utility>

int star_count[26];
using namespace std;
int main() {
    for (int i = 1; i <= 10;i++) star_count[i] = 5;
    for (int i = 11; i <= 15;i++) star_count[i] = 4;
    for (int i = 16; i <= 20;i++) star_count[i] = 3;
    for (int i = 21; i <= 25;i++) star_count[i] = 2;

    string sequence;
    getline(cin, sequence);

    int rank = 25, star = 0;
    int consecutive_wins = 0;

    for (char c : sequence) {
        if (rank <= 0) {
            break;
        }
        if (c == 'W') {
            consecutive_wins++;
            star++;
            if (consecutive_wins >= 3 && rank >= 6 && rank <= 25) {
                star++;
            }
            //cout << rank << ' ' << star << endl;;
            int carry = star - star_count[rank];
            if (carry > 0) {
                star = carry;
                rank--;
            }
        } else {
            consecutive_wins=0;
            if (rank == 20 && star == 0) continue;
            if (rank > 20) continue;
            
            if (star == 0) {
                rank++;
                star = star_count[rank] - 1;
            } else {
                star--;
            }
        }
    }
    if (rank <= 0) cout << "Legend" << endl;
    else cout << rank << endl;
}
