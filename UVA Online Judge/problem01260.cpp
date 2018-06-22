#include <cstdio>

int main() {
    
    int t, n, a[1001];
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j] <= a[i]) ans++;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}