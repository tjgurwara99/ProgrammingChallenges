#include <cstdio>
#define max(a,b) (((a) < (b)) ? (b) : (a))

int N, A[100][100];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) scanf("%d", &A[i][j]);
    }

    for (int i = N-2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) A[i][j] += max(A[i+1][j], A[i+1][j+1]);
    }

    printf("%d\n", A[0][0]);
    return 0;
}
