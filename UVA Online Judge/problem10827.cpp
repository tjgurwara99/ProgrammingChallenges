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

                for (int r = 0; r < N; r++) {
                    int s = r;
                    int currentSum = 0;
                    do {
                        currentSum += rowSum[s];

                        if (currentSum > maxSum) maxSum = currentSum;
                        else if (currentSum < 0) currentSum = 0;

                        s = (s+1) % N;
                    } while (s != r);
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
