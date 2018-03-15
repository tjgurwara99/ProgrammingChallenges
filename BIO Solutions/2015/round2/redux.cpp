#include <cstdio>

int main() {
    int N, T[MAXN], a, b, ans = 0;
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &T[i]);
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &a, &b);
        if (T[a]+T[b] > ans) ans = T[a]+T[b];
    }
    
    printf("%d\n", ans);
    
    return 0;
}