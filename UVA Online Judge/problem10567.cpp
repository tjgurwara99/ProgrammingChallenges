#include <iostream>
using namespace std;

string S, SS;
int N, Q, nextChar[1001001][52];

inline int toNum(char c) { return c >= 'a' ? (c-'a') : (c-'A'+26); }

int main() {

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> S >> Q;
    N = (int)S.size();
    for (int i = 0; i < 52; i++) nextChar[N][i] = -1;
    for (int i = N-1; i >=0; --i) {
        for (int j = 0; j < 52; j++) nextChar[i][j] = nextChar[i+1][j];
        nextChar[i][toNum(S[i])] = i;
    }

    while (Q--) {
        cin >> SS;
        int pos = nextChar[0][toNum(SS[0])], M = (int)SS.size();
        for (int i = 1; i < M && pos != -1; i++) pos = nextChar[pos+1][toNum(SS[i])];
        if (pos == -1) cout << "Not matched\n";
        else cout << "Matched " << nextChar[0][toNum(SS[0])] << " " << pos << "\n";
    }

    return 0;
}