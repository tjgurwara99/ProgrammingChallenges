#include <stdio.h>

int N, P, i, p, A[100];
unsigned long long DP[20000];

int main() {
    scanf("%d %d", &N, &P);
    for (i = 0; i < P; i++) scanf("%d", &A[i]);
    
    DP[0] = 1;
    for (p = 0; p < P; p++) for (i = A[p]; i <= N; i++) DP[i] += DP[i - A[p]];
    printf("%llu\n", DP[N]);
}