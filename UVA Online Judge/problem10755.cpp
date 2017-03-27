#include <cstdio>
#define ll long long

int main() {
    
    int T, A, B, C;
    ll grid[25][25][25], prefixSum[25][25][25];

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &A, &B, &C);
        
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                for (int k = 0; k < C; k++) {
                    scanf("%lld", &grid[i][j][k]);
                    prefixSum[i][j][k] = grid[i][j][k];

                    if (i) prefixSum[i][j][k] += prefixSum[i-1][j][k];
                    if (j) prefixSum[i][j][k] += prefixSum[i][j-1][k];
                    if (k) prefixSum[i][j][k] += prefixSum[i][j][k-1];

                    if (i && j) prefixSum[i][j][k] -= prefixSum[i-1][j-1][k];
                    if (i && k) prefixSum[i][j][k] -= prefixSum[i-1][j][k-1];
                    if (j && k) prefixSum[i][j][k] -= prefixSum[i][j-1][k-1];

                    if (i && j && k) prefixSum[i][j][k] += prefixSum[i-1][j-1][k-1];
                }
            }
        }

        ll currentValue = 0, maxValue = 0;

        /*
         * - Pick 2 points in A,B plane
         * - Apply Kadanes algorithm in C plane
         *    -> O(n^5) = 20^5 * 15 ~ 50 million OK.
         * */

#define PLANESUM(a, b, c) c == 0 ? prefixSum[a][b][0] : (prefixSum[a][b][c] - prefixSum[a][b][c-1])

        for (int x = 0; x < A; x++) {
            for (int y = 0; y < B; y++) {
                for (int p = x; p < A; p++) {
                    for (int q = y; q < B; q++) {

                        currentValue = 0;
                        for (int i = 0; i < C; i++) {
                            currentValue += PLANESUM(p, q, i);
                            if (x) currentValue -= PLANESUM(x-1, q, i);
                            if (y) currentValue -= PLANESUM(p, y-1, i);
                            if (x && y) currentValue += PLANESUM(x-1, y-1, i);

                            if (currentValue < 0) currentValue = 0;
                            if (currentValue > maxValue) maxValue = currentValue;
                        }
                    }
                }
            }
        }

        if (maxValue == 0) {
            maxValue = grid[0][0][0];
            for (int i = 0; i < A; i++) {
                for (int j = 0; j < B; j++) {
                    for (int k = 0; k < C; k++) {
                        if (grid[i][j][k] > maxValue) maxValue = grid[i][j][k];
                    }
                }
            }
        }

        printf("%lld\n", maxValue);
        if (T) printf("\n");
    }
    
    return 0;
}
