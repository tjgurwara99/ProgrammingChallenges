#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N, M, A[501][501], Q, L, U;

inline int getMaxSize() {
    int topMin = 0, topLen = M;

    if (A[0][M-1] < L) return 0;

    while (topLen > 0) {
        int halfLen = topLen / 2;
        if (A[0][topMin + halfLen] < L) {
            topMin += halfLen+1;
            topLen -= halfLen+1;
        } else {
            topLen = halfLen;
        }
    }

    int botMin = 0, botLen = M;
    if (A[N-1][0] > U) return 0;
    
    while (botLen > 0) {
        int halfLen = botLen / 2;
        if (A[N-1][botMin + halfLen] <= U) {
            botMin += halfLen+1;
            botLen -= halfLen+1;
        } else {
            botLen = halfLen;
        }
    }

    return min(botMin-topMin, N);
}

int main() {

    while (scanf("%d %d", &N, &M), N & M) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) scanf("%d", &A[i][j]);
        }
        scanf("%d", &Q);

        for (int q = 0; q < Q; q++) {
            scanf("%d %d", &L, &U);
            printf("%d\n", getMaxSize());
        }
    }

    return 0;
}
