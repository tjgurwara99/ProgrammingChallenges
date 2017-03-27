#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N, M, A[501][501], Q, L, U;

inline int getMaxSize() {
    int topMin = 0, topLen = M;
    int maxLen = 0;

    for (int i = 0; i+maxLen < N; i++) {
        topMin = 0;
        topLen = M;
        while (topLen > 0) {
            int halfLen = topLen / 2;
            if (A[i][topMin + halfLen] < L) {
                topMin += halfLen+1;
                topLen -= halfLen+1;
            } else {
                topLen = halfLen;
            }
        }

        for (int j = maxLen+1; topMin+j<=M && i+j <= N; j++) {
            if (A[i+j-1][topMin+j-1] > U) break;
            maxLen = j;
        }
    }

    return maxLen;
}

int main() {

    while (scanf("%d %d", &N, &M), N | M) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) scanf("%d", &A[i][j]);
        }
        scanf("%d", &Q);

        for (int q = 0; q < Q; q++) {
            scanf("%d %d", &L, &U);
            printf("%d\n", getMaxSize());
        }
        printf("-\n");
    }

    return 0;
}
