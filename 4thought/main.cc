#include <iostream>

using namespace std;

int eval(int a, int b, int c) {
    int operands_left = 4;
    int operands[4] = {4, 4, 4, 4};
    int ops[] = {a, b, c};
    while (operands_left > 1) {
        int op_to_use = ops[0];
        int evalat = 0;
        for (int i = 1; i < (operands_left - 1); i++) {
            if (ops[i] >= 2 && op_to_use < 2) {
                op_to_use = ops[i];
                evalat = i;
            }
        }
        for (int i = evalat; i < 3; i++) ops[i] = ops[i+1];

        const int l = operands[evalat];
        const int r = operands[evalat+1];
        int rst = -9999;
        if (op_to_use == 0) {
            rst = l + r;
        } else if (op_to_use == 1) {
            rst = l - r;
        } else if (op_to_use == 2) {
            rst = l * r;
        } else {
            if (r == 0) return 4 * 4 * 4 * 10;
            rst = l / r;
        }
        operands[evalat] = rst;
        for (int i = evalat+1; i < 3; i++) {
            operands[i] = operands[i+1];
        }
        operands_left--;
    }
    return operands[0];
}

int main() {
    int n;
    cin >> n;
    const char* ops[] = {"+ ", "- ", "* ", "/ "};
    const char* fourspace = "4 ";
    while (n--) {
        int goal;
        cin >> goal;


        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++) {
                    double evalr = eval(i, j, k);
                    if (evalr == goal) {
                        cout << fourspace << ops[i] << fourspace << ops[j] << fourspace << ops[k] << fourspace << "= " << evalr << '\n';
                        goto next;
                    }
                }
        cout << "no solution\n";
next:;
    }
}
