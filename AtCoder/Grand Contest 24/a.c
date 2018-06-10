#include <stdio.h>
int main() {
    long long A, B, C, K;
    scanf("%lld %lld %lld %lld", &A, &B, &C, &K);
    printf("%lld\n", (K%2)?(B-A):(A-B));
    return 0;
}