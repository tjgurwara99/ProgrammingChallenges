#include <cstdio>

int main() {
    int k, A[13], first = 1;
    while (scanf("%d", &k), k) {
        for (int i = 0; i < k; i++) scanf("%d",A+i);
        
        if (!first) printf("\n");
        first = 0;
        
        for (int a = 0; a < k; a++)
        for (int b = a+1; b < k; b++) 
        for (int c = b+1; c < k; c++)
        for (int d = c+1; d < k; d++) 
        for (int e = d+1; e < k; e++) 
        for (int f = e+1; f < k; f++) {
            printf("%d %d %d %d %d %d\n", A[a], A[b], A[c], A[d], A[e], A[f]);
        }
    }
    return 0;
}