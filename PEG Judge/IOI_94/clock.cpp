#include <iostream>
#include <string>
using namespace std;

char DP[1<<18], stateMove[1<<18];

string moves[9] = {
    "ABDE", "ABC", "BCEF", "ADG", "BDEFH",
 	"CFI", "DEGH", "GHI", "EFHI"
};
bool moveTurn[9][9];
int state[9];

inline int getIdx() {
    int stateIdx = 0;
    for (int i = 0; i < 9; i++) {
        stateIdx = (stateIdx<<2) + (state[i] & 3);
    }
    return stateIdx;
}

char search(int minIdx) {
    int stateIdx = getIdx();
    if (!stateIdx) return 0;
    
    if (!DP[stateIdx]) {
        DP[stateIdx] = 100;
        for (int i = minIdx; i < 9; i++) {
            for (int k = 0; k < 3; k++) {
                for (int j = 0; j < 9; j++) {
                    if (moveTurn[i][j]) state[j]++;
                }
                char a = 1 + search(i+1);
                if (a < DP[stateIdx]) {
                    DP[stateIdx] = a;
                    stateMove[stateIdx] = 3 * i + k;
                }
            }
            for (int j = 0; j < 9; j++) {
                if (moveTurn[i][j]) state[j] -= 3;
            }
        }
    }
    return DP[stateIdx];
}

int main() {
    
    for (int i = 0; i < 9; i++) {
        for (char c: moves[i]) moveTurn[i][c-'A'] = true;
    }
    
    for (int i = 0; i < 9; i++) {
        cin >> state[i];
        state[i] = (state[i] % 12) / 3;
    }
    int moveCount = (int)search(0);
    
    
    bool first = true;
    for (int idx = getIdx(); idx; idx = getIdx()) {
        for (int i = 0; i <= (stateMove[idx] % 3); i++) {
            if (!first) cout << " ";
            first = false;
            cout << (stateMove[idx]/3 + 1);
        }
        for (int i = 0; i < 9; i++) {
            if (moveTurn[stateMove[idx]/3][i]) state[i] += (stateMove[idx] % 3) + 1;
        }
    }
    cout << endl;
    
    return 0;
}