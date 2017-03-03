#include <iostream>
#include <string>
using namespace std;

#define MAXN 5001

enum VAROP { LIT, XOR, AND, OR };

int N, M;

string varNames[MAXN];
string varValues[MAXN];
VAROP varOp[MAXN];
int varLeftArg[MAXN], varRightArg[MAXN];

int findVariable(const string& name) {
    if (name == "?") return -1;
    for (int i = 0; i < N; i++) {
        if (name == varNames[i]) return i;
    }
    cout << "ERROR variable not found" << endl;
    return -1;
}

int bitValues[MAXN];

inline int getValue(int varIdx, bool isOne) {
    if (varIdx == -1) return isOne ? 1 : 0;
    return bitValues[varIdx];
}

inline int getValue(int idx, int bitPos, bool isOne) {
    int v = 0;
    switch (varOp[idx]) {
        case LIT:
            v = varValues[idx][bitPos] == '0' ? 0 : 1;
            break;
        case XOR:
            v = getValue(varLeftArg[idx], isOne) ^ getValue(varRightArg[idx], isOne);
            break;
        case AND:
            v = getValue(varLeftArg[idx], isOne) & getValue(varRightArg[idx], isOne);
            break;
        case OR:
            v = getValue(varLeftArg[idx], isOne) | getValue(varRightArg[idx], isOne);
            break;

    }
    return v;
}

int getBitCount(int bitPos, bool isOne) {
    int total = 0;
    for (int i = 0; i < N; i++) {
        bitValues[i] = getValue(i, bitPos, isOne);
        total += bitValues[i];
    }
    return total;
}

int main() {

    cin >> N >> M;
    string temp, lhs, op, rhs;

    for (int i = 0; i < N; i++) {
        cin >> varNames[i] >> temp >> lhs;

        // binary literal
        if (lhs[0] == '0' || lhs[0] == '1') {
            varOp[i] = LIT;
            varValues[i] = lhs;
        // operation
        } else {
            cin >> op >> rhs;
            varLeftArg[i] =  findVariable(lhs);
            varRightArg[i] =  findVariable(rhs);

            if (op == "XOR") {
                varOp[i] = XOR;
            } else if (op == "OR") {
                varOp[i] = OR;
            } else if (op == "AND") {
                varOp[i] = AND;
            } else {
                cout << "ERROR BEWARE " << lhs << endl;
            }
        }
    }

    string minstr = "";
    string maxstr = "";


    for (int bitPos = 0; bitPos < M; bitPos++) {
        int one = getBitCount(bitPos, true);
        int zero = getBitCount(bitPos, false);
        if (one > zero) {
            maxstr += "1";
            minstr += "0";
        } else if (one < zero) {
            maxstr += "0";
            minstr += "1";
        } else {
            maxstr += "0";
            minstr += "0";
        }
    }
    
    cout << minstr << endl;
    cout << maxstr << endl;

    return 0;
}
