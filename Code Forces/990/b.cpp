#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 300000

int N, K, A[MAXN];

int main() {

    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    sort(A, A+N);

    int ans = 0, sameCount = 1;
    for (int i = 1; i < N; i++) {
        if (A[i] - A[i-1] > K) ans += sameCount; 

        if (A[i] == A[i-1]) sameCount++;
        else sameCount = 1;
    }
    ans += sameCount;
    printf("%d\n", ans);

    return 0;
}
