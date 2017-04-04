#include <cstdio>

int main() {
    
    int n, x, sum = 0, bestSum = -101;
    scanf("%d", &n);
    
    while (n--) {
        scanf("%d", &x);
        sum += x;
        if (sum > bestSum) bestSum = sum;
        if (sum < 0) sum = 0;
    }
    
    printf("%d\n", bestSum);
    
    return 0;
}