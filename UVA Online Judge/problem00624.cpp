#include <cstdio>

int N, M, A[21];

int main() {
    
    while (scanf("%d", &N) != EOF) {
        scanf("%d", &M);
        for (int i = 0; i < M; i++) scanf("%d", &A[i]);
        
        int bestAns = 0, bestSum = 0;
        for (int i = 0; i < (1 << M); i++) {
            int sum = 0;
            for (int j = 0; j < M; j++) {
                if (i & (1 << j)) sum += A[j];
            }
            if (sum <= N && sum >= bestSum) {
                bestSum = sum;
                bestAns = i;
            }
        }
        
        for (int i = 0; i < M; i++) {
            if (bestAns & (1 << i)) printf("%d ", A[i]);
        }
        printf("sum:%d\n", bestSum);
    }
    
    return 0;
}