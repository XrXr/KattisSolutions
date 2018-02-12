#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

#define MAX_NUM 150

int main() {
    int numbers[MAX_NUM];
    char ops[MAX_NUM];
    string line;
    bool first = true;
    while (getline(cin, line)) {
        if (!first) {
            cout << endl;
        }
        first = false;
        memset(numbers, 0, MAX_NUM);
        memset(ops, 0, MAX_NUM);
        int num;
        stringstream formula(line);
        int i = 0;
        while (formula >> num) {
            string op;
            formula >> op;
            numbers[i] = num;
            ops[i] = op[0];
            i++;
        }
        /*
        for (int j = 0; j < i; j++) {
            cout << "the " << j << "th number is " << numbers[j] << " op after it is " << ops[j] << endl;
        } */
        set<int> dp[MAX_NUM][MAX_NUM];
        const int numberOfNums = i;
        for (i = 0; i < numberOfNums; i++) {
            dp[i][1].insert(numbers[i]);
        }
        for (i = 2; i <= numberOfNums; i++) {
            for (int j = 0; j <= (numberOfNums-i); j++) {
                /*
                a * b + c + d
                0 0 1 1 2 2 3
                j = 0
                i = 4
                k = 2
                */
                for (int k = 0; k < (i-1); k++) {
                    //printf("i %d j %d k %d\n", i, j, k);
                    //printf("left dp[%d][%d], right dp[%d][%d]\n", j, k+1, k+1, i-k-1);
                    for (auto left : dp[j][k+1])
                        for (auto right : dp[j+k+1][i-k-1]) {
                            int result= -1234123424;
                            switch (ops[j+k]) {
                            case '+':
                                result = left + right;
                                break;
                            case '-':
                                result = left - right;
                                break;
                            case '*':
                                result = left * right;
                                break;
                            }

                            //cout << result << endl;
                            dp[j][i].insert(result);
                        }
                }
            }
        }
        for (auto e : dp[0][numberOfNums])
            cout << e << endl;
    }
}
