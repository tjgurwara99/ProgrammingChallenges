#include <cstdio>

int main() {
    int S, D, ans;
    while (scanf("%d %d", &S, &D) != EOF) {
        ans = -1;
        for (int i = 0; i < (1 << 12); i++) {
            int sum = 0;
            for (int j = 0; j < 12; j++) {
                sum += (i & (1 << j)) ? S : -D;
            }
            if (sum < ans) continue;
            
            bool valid = true;
            for (int j = 0; j < 8; j++) {
                int total = 0;
                for (int k = j; k < j+5; k++) {
                    total += (i & (1 << k)) ? S : -D;
                }
                if (total >= 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) ans = sum;
        }
        if (ans > 0) printf("%d\n", ans);
        else printf("Deficit\n");
    }
    
    return 0;
}