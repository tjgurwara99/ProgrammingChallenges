#include <cstdio>
#include <cmath>

int main() {
    int N, T, K, D;
    scanf("%d %d %d %d", &N, &T, &K, &D);
    int t1 = ceil((N * 1.0) / K)*T;

    if (t1-T <= D) printf("NO\n");
    else           printf("YES\n");
    return 0;
}
