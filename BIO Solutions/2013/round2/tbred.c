#include <stdio.h>

#define MAXN (1 << 21)

int P[MAXN], I[MAXN], nodeParent[MAXN], N;

void construct(int parent, int pidx, int iidx, int len) {
    int i;
    
    nodeParent[P[pidx]] = parent;
    if (len <= 1) return;
    
    for (i = iidx; I[i] != P[pidx]; i++) ;
    
    construct(P[pidx], pidx+1, iidx, i-iidx);
    construct(P[pidx], pidx+1+(i-iidx), i+1, len - (i-iidx) - 1);
}

int main() {
    
    int i;
    scanf("%d", &N);
    
    for (i = 0; i < N; i++) scanf("%d", &P[i]);
    for (i = 0; i < N; i++) scanf("%d", &I[i]);
    
    construct(0, 0, 0, N);
    for (i = 1; i <= N; i++) printf("%d\n", nodeParent[i]);
    
    return 0;
}