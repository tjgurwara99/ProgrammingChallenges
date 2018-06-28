#include <cstdio>
bool reachable[1001];
int main() {
    int T, N, P, A[30];
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &P);
        for (int i = 0; i < P; i++) scanf("%d", &A[i]);
        for (int i = 0; i <= N; i++) reachable[i] = false;
        reachable[0] = true;
        for (int p = 0; p < P; p++) {
            for (int i = N-A[p]; i >= 0; --i) reachable[i+A[p]] |= reachable[i];
        }
        printf(reachable[N] ? "YES\n" : "NO\n");
    }
    return 0;
}