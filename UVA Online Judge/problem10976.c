#include <stdio.h>
int main() {
    int k, x, y, ans;
    while (scanf("%d", &k) != EOF) {
        ans = 0;
        for (y = k+1; y <= 2*k; y++) {
            if ((y*k) % (y-k) == 0) ++ans;
        }
        printf("%d\n", ans);
        for (y = k+1; y <= 2*k; y++) {
            if ((y*k) % (y-k) == 0) {
                x = (y*k)/(y-k);
                printf("1/%d = 1/%d + 1/%d\n", k, x, y);
            }
        }
    }
    return 0;
}