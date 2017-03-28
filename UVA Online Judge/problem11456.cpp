#include <cstdio>

int main() {

    int T, N, A[2001], DP[2001][2];
    
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int maxAns = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            DP[i][0] = 0;
            DP[i][1] = 0;
            for (int j = 0; j < i; j++) {
                if (A[j] >= A[i] && DP[j][0] > DP[i][0]) {
                    DP[i][0] = DP[j][0];
                }
                if (A[j] <= A[i] && DP[j][1] > DP[i][1]) {
                    DP[i][1] = DP[j][1];
                }
            }
            DP[i][0]++;
            DP[i][1]++;
            if (DP[i][0] > maxAns) maxAns = DP[i][0];
            if (DP[i][1] > maxAns) maxAns = DP[i][1];
        }
        printf("%d\n", maxAns);
    }


    return 0;
}
