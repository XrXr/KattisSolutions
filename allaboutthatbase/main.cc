#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<char> symbols;
struct {
    bool good;
    long long value;
} powTable[37][100];

const long long limit = (1ll << 32ll) - 1;

bool parse(int base, const string& in, long long& out) {
    out = 0;
    if (base == 1) {
        for (auto c : in) {
            if (c != '1') {
                return false;
            }
            out++;
        }
        return true;
    }
    for (int i = 0; i < in.size(); i++) {
        char c = in[i];
        for (int j = 0; j < symbols.size(); j++) {
            if (symbols[j] == c) {
                int impliedBase = j+1;
                if (impliedBase > base) {
                    return false;
                }
                if (powTable[base][i].good) {
                    out += j * powTable[base][i].value;
                }else {
                    return false;
                }
                break;
            }
        }
        if (out > limit) return false;
    }
    return out <= limit;
}

int main() {
    for (char c = '0'; c <= '9'; c++) symbols.push_back(c);
    for (char c = 'a'; c <= 'z'; c++) symbols.push_back(c);
    //cout << limit << endl;
    //for (auto c : symbols) cout << c; cout << endl;
    for (int i = 1; i <= 36; i++) {
        int j;
        powTable[i][0].good=true;
        powTable[i][0].value=1;
        for (j = 1; j < 100; j++) {
            long long result = powTable[i][j-1].value * i;
            if (result > limit) {
                break;
            }
            powTable[i][j].good=true;
            powTable[i][j].value=result;
        }
        // powTable being global automatically sets the rest to false
    }


    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string in, left, right, result;
        int op, equal;
        char optok;
        getline(cin, in);
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == '/' || in[i] == '*' || in[i] == '+' || in[i] == '-') {
                op = i;
                optok = in[i];
            }
            if (in[i] == '=') {
                equal = i;
            }
        }
        left = in.substr(0, op-1);
        right = in.substr(op+2, equal - (op+2)-1);
        result = in.substr(equal+2);
        reverse(left.begin(), left.end());
        reverse(right.begin(), right.end());
        reverse(result.begin(), result.end());
        //cout << "left " << left << " right " << right << " result " << result << endl;
        string feasibleBases;
        for (int i = 1; i <=36; i++) {
        //for (int i = 16; i <=16; i++) {
            long long leftParse, rightParse, resultParse;
            bool ok;
            ok = parse(i, left, leftParse);
            ok = ok && parse(i, right, rightParse);
            ok = ok && parse(i, result, resultParse);
            if (ok) {
                //cout << leftParse << ' ' << rightParse << ' ' << resultParse << endl;
                long long compute;
                bool divgood = true;
                switch (optok){
                case '+':
                    compute = leftParse+rightParse;
                    break;
                case '-':
                    compute = leftParse-rightParse;
                    break;
                case '*':
                    compute = leftParse * rightParse;
                    break;
                case '/':
                    compute = leftParse/rightParse;
                    divgood = (compute * rightParse == leftParse);
                    break;
                };
                if (compute == resultParse && divgood) {
                    if (i == 36)
                        feasibleBases += '0';
                    else
                        feasibleBases += symbols[i];
                }
            }
        }
        if (feasibleBases.size() == 0)
            cout << "invalid" << endl;
        else
            cout << feasibleBases << endl;
    }
}
