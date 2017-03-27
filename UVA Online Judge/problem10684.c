#include <stdio.h>
int main() {
    int N, i, maxSum, sum, x;
    while (scanf("%d", &N), N) {
        maxSum = sum = 0;
        for (i = 0; i < N; i++) {
            scanf("%d", &x);
            sum += x;
            if (sum > maxSum) maxSum = sum;
            if (sum < 0) sum = 0;
        }
        if (maxSum) printf("The maximum winning streak is %d.\n", maxSum);
        else        printf("Losing streak.\n");
    }
    return 0;
}
