#include <cstdio>

int main() {

    int N, Q, A[200], t = 0;
    long long DP[11][200][21][20]; 

    while (scanf("%d %d", &N, &Q), N & Q) {
        
        for (int m = 0; m < 11; m++) {
            for (int i = 0; i < N; i++) {
                for (int d = 0; d < 21; d++) {
                    for (int r = 0; r < d; r++) {
                        DP[m][i][d][r] = 0;
                    }
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            for (int d = 1; d <= 20; d++) DP[1][i][d][A[i]%d] = 1;
        }

        for (int m = 2; m <= 10; m++) {
            for (int i = 0; i <= N-m; i++) {
                for (int d = 1; d <= 20; d++) {
                    for (int r = 0; r < d; r++) {
                        int c = (d-((r+A[i])%d))%d;
                        for (int j = i+1; j <= N-m+1; j++) {
                            DP[m][i][d][r] += DP[m-1][j][d][c];
                        }
                    }
                }
            }
        }

        printf("SET %d:\n", ++t);
        for (int q = 0; q < Q; q++) {
            int D, M;
            scanf("%d %d", &D, &M);
            long long ans = 0;
            for (int i = 0; i <= N-M; i++) ans += DP[M][i][D][0];
            printf("QUERY %d: %lld\n", q+1, ans);
        }
    }

    return 0;
}
