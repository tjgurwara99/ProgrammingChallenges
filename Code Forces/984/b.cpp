#include <cstdio>

int N, M, grid[101][101];

inline int countBombs(int r, int c) {
    int count = 0;
    for (int dr = -1; dr < 2; dr++) {
        for (int dc = -1; dc < 2; dc++) {
            if (!dr && !dc) continue;
            int r2 = r+dr,c2=c+dc;
            if (r2 < 0 || r2 >= N) continue;
            if (c2 < 0 || c2 >= M) continue;
            if (grid[r2][c2] == -1) ++count;
        }
    }
    return count;
}

int main() {
    
    scanf("%d %d", &N, &M);
    
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            char g;
            scanf(" %c", &g);
            if (g == '*') grid[r][c] = -1;
            else if (g != '.') grid[r][c] = g-'0';
        }
    }
    
    bool valid = true;
    
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (grid[r][c] == -1) continue;
            if (countBombs(r, c) != grid[r][c]) {
                valid = false;
                break;
            }
        }
        if (!valid) break;
    }
    
    printf(valid ? "YES\n" : "NO\n");
    
    return 0;
}