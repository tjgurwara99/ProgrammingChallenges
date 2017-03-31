#include <cstdio>

int main() {

    int T, M, N, A[105], DP[30000];
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &M);
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);
        for (int i = 1; i <= 20000; i++) DP[i] = -1;
        DP[0] = 0;
        for (int c = 0; c < N; c++) {
            int coin = A[c];
            for (int i = 20000; i >= coin; i--) {
                if (DP[i-coin] != -1 && (DP[i-coin]+1 < DP[i] || DP[i] == -1) ) {
                    DP[i] = DP[i-coin]+1;
                }
            }
        }

        int idx = M;
        while (DP[idx] == -1) idx++;
        printf("%d %d\n", idx, DP[idx]);
    }

    return 0;
}
