#include <cstdio>
#define ll long long

inline int mod(int m, int d) {
    m %= d;
    if (m < 0) m += d;
    return m;
}

int main() {

    int N, Q, D, M, A[200], t = 0;
    ll DP[11][201][20];

    while (scanf("%d %d", &N, &Q), N & Q) {
        
        for (int i = 0; i < N; i++)  scanf("%d", &A[i]);

        printf("SET %d:\n", ++t);
        for (int q = 0; q < Q; q++) {
            scanf("%d %d", &D, &M);
            
            // f(m, i, r) = no. of ways to choose m from [i..] summing to r mod D
            // f(m, i, r) = f(m-1, i+1, r1) + f(m, i+1, r2)
            for (int i = 0; i <= N; i++) {
                DP[0][i][0] = 1;
                for (int r = 1; r < D; r++) DP[0][i][r] = 0;
            }
            
            for (int m = 1; m <= M; m++) {
                for (int i = N-m; i >= 0; i--) {
                    for (int r = 0; r < D; r++) {
                        int c = mod(r - A[i], D);
                        DP[m][i][r] = DP[m-1][i+1][c];
                        if (i < N-m) DP[m][i][r] += DP[m][i+1][r];
                    }
                }
            }
            
            printf("QUERY %d: %lld\n", q+1, DP[M][0][0]);
        }
    }

    return 0;
}