#include <cstdio>

#define MAXN 32
int N, A[MAXN][MAXN], rowChoice[MAXN], colChoice[MAXN];

int main() {
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
        rowChoice[i] = i;
    }
    
    while (true) {
        int maxRowI = -1, maxRowJ = -1, maxChange = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                int current = A[i][rowChoice[i]] + A[j][rowChoice[j]];
                int changed = A[i][rowChoice[j]] + A[j][rowChoice[i]];
                
                if (current - changed > maxChange) {
                    maxChange = current - changed;
                    maxRowI = i;
                    maxRowJ = j;
                }
            }
        }
        
        if (maxRowI == -1) break;
        
        int temp = rowChoice[maxRowI];
        rowChoice[maxRowI] = rowChoice[maxRowJ];
        rowChoice[maxRowJ] = temp;
    }
    
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += A[i][rowChoice[i]];
        colChoice[rowChoice[i]] = i;
    }
    
    printf("%d\n", total);
    for (int i = 0; i < N; i++) printf("(%d,%d)\n", i+1, colChoice[i]+1);
    
    return 0;
}