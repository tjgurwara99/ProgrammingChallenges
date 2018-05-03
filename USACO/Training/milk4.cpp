/*
ID: basimkh1
PROG: milk4
LANG: C++11
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXQ 20001
#define MAXP 101

int Q, P, A[MAXP];
bool used[MAXP], possible[MAXQ];

bool dfs(int j, int d) {
    if (d == 0) {
        fill(possible, possible+Q+1, false);
        possible[0] = true;
        for (int q = 0; q <= Q; q++) {
            if (!possible[q]) continue;
            for (int p = 0; p < P; p++) {
                if (A[p] + q > Q) break;
                if (used[p]) {
                    possible[A[p] + q] = true;
                    if (A[p] + q == Q) return true;
                }
            }
        }
        return false;
    }
    for (int i = j; i < P; i++) {
        used[i] = true;
        if (dfs(i+1, d-1)) return true;
        used[i] = false;
    }
    return false;
}

int main() {
    
    freopen("milk4.in", "r", stdin); freopen("milk4.out", "w", stdout);
    
    cin >> Q >> P;
    for (int i = 0; i < P; i++) cin >> A[i];
    sort(A, A+P);
    
    for (int i = 1; i <= P; i++) {
        if (dfs(0, i)) {
            cout << i;
            for (int j = 0; j < P; j++) {
                if (used[j]) cout << " " << A[j];
            }
            cout << "\n";
            break;
        }
    }
    
    return 0;
}