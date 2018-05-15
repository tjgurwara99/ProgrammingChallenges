#include <iostream>
using namespace std;

int N, K;
bool grid[4][100];

#define MOD 1000003

bool gridEqual() {
    
    int dp1[4][100]; // right down
    int dp2[4][100]; // right up
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < N; j++) {
            dp1[i][j] = dp2[i][j] = 0;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        dp1[i][0] = 1;
        dp2[i][0] = 1;
    }
    for (int i = 0; i < N; i++) {
        dp1[0][i] = 1;
        dp2[3][i] = 1;
    }
    
    for (int c = 1; c < N; c++) {
        for (int r = 1; r < 4; r++) {
            if (grid[r][c]) continue;
            dp1[r][c] = (dp1[r-1][c] + dp1[r][c-1]) % MOD;
        }
        for (int r = 3; r >= 0; --r) {
            if (grid[r][c]) continue;
            dp2[r][c] = (dp2[r-1][c] + dp2[r][c+1]) % MOD;
        }
    }
    
    return dp1[3][N-1] == dp2[0][N-1];
}

int main() {
    
    cin >> N >> K;
    
    bool found = false;
    
    if (K == 1) { 
        for (int i = 1; i < N-1; i++) {
            grid[1][i] = true;
            if (gridEqual()) {
                found = true;
                break;
            }
            grid[1][i] = false;
        }
    }
    else if (K == 3) {
        
        for (int i = 1; i < N-1; i++) {
            grid[i][1] = grid[i][2] = true;
            for (int j = i+1; i < N-1; i++) {
                grid[j][1] = true;
                if (gridEqual()) {
                    found = true;
                    break;
                }
                grid[j][1] = false;
            }
            if (found) break;
            grid[i][1] = grid[i][2] = false;
        }
        
        if (!found) {
            for (int i = 1; i < N-1; i++) {
                grid[i][1] = true;
                for (int j = i+1; j < N-1; j++) {
                    grid[j][1] = true;
                    for (int k = j+1; k < N-1; k++) {
                        grid[k][1] = true;
                        if (gridEqual()) {
                            found = true;
                            break;
                        }
                        grid[k][1] = false;
                        
                        grid[k][2] = true;
                        if (gridEqual()) {
                            found = true;
                            break;
                        }
                        grid[k][2] = false;
                    }
                    if (found) break;
                    grid[j][1] = false;
                    
                    grid[j][2] = true;
                    for (int k = j+1; k < N-1; k++) {
                        grid[k][1] = true;
                        if (gridEqual()) {
                            found = true;
                            break;
                        }
                        grid[k][1] = false;
                        
                        grid[k][2] = true;
                        if (gridEqual()) {
                            found = true;
                            break;
                        }
                        grid[k][2] = false;
                    }
                    if (found) break;
                    grid[j][2] = false;
                }
                if (found) break;
                grid[i][1] = false;
            }
        }
    }
    else {
        found = true;
        if (K % 2) {
            grid[1][1] = grid[2][1] = true;
            K -= 2;
            int i = 2;
            while (K > 3) {
                grid[1][i] = grid[2][i] = true;
                i++;
                K -= 2;
            }
            grid[1][i] = true;
            grid[1][i+1] = grid[2][i+1] = true;
        } else {
            for (int i = 1; i < N-1 && K; i++) {
                grid[1][i] = grid[2][i] = true;
                K -= 2;
            }
        }
    }
    
    if (found) {
        cout << "YES\n";
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < N; c++) cout << (grid[r][c] ? '#' : '.');
            cout << "\n";
        }
    } else {
        cout << "NO\n";
    }
    
    return 0;
}