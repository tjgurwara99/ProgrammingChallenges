#include <cstdio>

int grid[15][15], DP[1 << 15];

int solve(int mask, int row) {
    if (row == 15) return 0;
    if (DP[mask]) return DP[mask];
    for (int i = 0; i < 15; i++) {
        if (mask & (1 << i)) continue;
        int ans = grid[row][i] + solve(mask | (1<<i), row+1);
        if (ans > DP[mask]) DP[mask] = ans;
    }
    return DP[mask];
}

int main() {
    
    FILE *f = fopen("p345.txt", "r");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) fscanf(f, " %d", &grid[i][j]);
    }
    fclose(f);
    
    printf("%d\n", solve(0, 0));
    
    return 0;
}