#include <cstdio>
int T, N, A[2001], LIS[2001], LDS[2001];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int maxAns = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
            LIS[i] = LDS[i] = 1;
        }
        for (int i = N-1; i >= 0; --i) {
            for (int j = i+1; j < N; ++j) {
                if (A[j] > A[i] && LIS[j] >= LIS[i]) LIS[i] = LIS[j]+1;
                if (A[j] < A[i] && LDS[j] >= LDS[i]) LDS[i] = LDS[j]+1;
            }
            if (LIS[i]+LDS[i] > maxAns) maxAns = LIS[i]+LDS[i]-1;
        }
        printf("%d\n", maxAns);
    }
    return 0;
}
