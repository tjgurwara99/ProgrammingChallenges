#include <cstdio>

int main() {
    
    int N, T, grid[76][76], rowSum[76];
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        
        int maxSum = 0;
        
        for (int u = 0; u < N; u++) {
            for (int r = 0; r < N; r++) rowSum[r] = 0;
            
            for (int l = 1; l <= N; l++) {
                int v = (u+l-1) % N;
                for (int r = 0; r < N; r++) rowSum[r] += grid[r][v];
                
                int currentSum = 0, lastStart = -1;
                bool reachedEnd = false;
                
                for (int r = 0; r != lastStart; r++) {
                    if (r == N) {
                        r = -1;
                        reachedEnd = true;
                        continue;
                    }
                    
                    if (currentSum == 0) lastStart = r;
                    currentSum += rowSum[r];
                    
                    if (currentSum > maxSum) maxSum = currentSum;
                    
                    if (currentSum < 0) {
                        currentSum = 0;
                        if (reachedEnd) break;
                    }
                }
            }
        }
        
        if (maxSum == 0) {
            maxSum = grid[0][0];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (grid[i][j] > maxSum) maxSum = grid[i][j];
                }
            }
        }
        
        printf("%d\n", maxSum);
    }
    
    return 0;
}