#include <bits/stdc++.h>
using namespace std;

int R, C, grid[600][600];

int main() {
    
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        string S;
        cin >> S;
        for (int c = 0; c < C; c++) {
            if (S[c] == 'S') {
                grid[r][c] = 1;
            } else if (S[c] == 'W') {
                grid[r][c] = 2;
            }
        }
    }
    
    bool directAttack = false;
    
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] != 2) continue;
            if (r && grid[r-1][c] == 1) directAttack = true;
            if (c && grid[r][c-1] == 1) directAttack = true;
            if (r<R-1 && grid[r+1][c] == 1) directAttack = true;
            if (c<C-1 && grid[r][c+1] == 1) directAttack = true;
        }
    }
    
    if (directAttack) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                cout << "DSW"[grid[r][c]];
            }
            cout << endl;
        }
    }
    
    return 0;
}