#include <cstdio>

#define ll unsigned long long

int N, A[30], D, K;

int main() {
    
    int T;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i <= N; i++) scanf("%d", &A[i]);
        scanf("%d %d", &D, &K);
        
        int idx = 1, count = D;
        while (count < K) count += (++idx) * D;
        
        ll num = 0, acc = 1;
        for (int i = 0; i <= N; i++) {
            num += acc * A[i];
            acc *= idx;
        }
        printf("%llu\n", num);
    }
    
    return 0;
}