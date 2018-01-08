#include <cstdio>
#define MAXN 400000
int N, A[MAXN];

int main() {
    
    scanf("%d", &N);
    printf("1");
    
    int correctIndex = N, p; 
    
    for (int i = 1; i <= N; i++) {
        scanf("%d", &p);
        A[p-1] = 1;
        while (correctIndex && A[correctIndex-1]) correctIndex--;
        printf(" %d",1+i-N+correctIndex);
    }
    printf("\n");
    
    return 0;
}