#include <cstdio>
#include <cstring>
#define ll long long
inline int mod(int m, int d) { return (d + (m%d))%d; }

// f(m,i r) = no. of ways to choose m from [i..] summing to r mod D
// f(m,i,r) = f(m-1,i+1,(r-a_i)) + f(m,i+1,r)
int main() {
    int N, Q, D, M, A[200], t = 0;
    ll DP[11][205][21];

    while (scanf("%d %d", &N, &Q), N | Q) {
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        printf("SET %d:\n", ++t);
        for (int q = 1; q <= Q; q++) {
            scanf("%d %d", &D, &M);
            memset(DP, 0, sizeof(ll)*11*205*21);
            for (int i = 0; i <= N; i++) DP[0][i][0] = 1;
            for (int m = 1; m <= M; m++) {
                for (int i = N-m; i >= 0; i--) {
                    for (int r = 0; r < D; r++) {
                        DP[m][i][r] = DP[m-1][i+1][mod(r-A[i], D)] + DP[m][i+1][r];
                    }
                }
            }
            printf("QUERY %d: %lld\n", q, DP[M][0][0]);
        }
    }
    return 0;
}
