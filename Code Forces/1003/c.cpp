#include <cstdio>
#include <algorithm>
using namespace std;

int N, K, A[10000];

int main() {

    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", A+i);
        A[i] += A[i-1];
    }

    double ans = 0;

    for (int k = K; k <= N; k++) {
        int maxTotal = 0;
        for (int i = 1; i <= N-k+1; i++) {
            maxTotal = max(maxTotal, A[i+k-1] - A[i-1]);
        }
        ans = max(ans, maxTotal * 1.0 / k);
    }

    printf("%0.10f\n", ans);

    return 0;
}