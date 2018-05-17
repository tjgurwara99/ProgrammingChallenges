#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 5001

int N, Q, A[MAXN];
int fRange[MAXN][MAXN], fMax[MAXN][MAXN];

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    
    for (int i = 0; i < N; i++) fRange[i][1] = A[i];
    for (int l = 2; l <= N; l++) {
        for (int i = 0; i+l <= N; i++) {
            fRange[i][l] = fRange[i][l-1] ^ fRange[i+1][l-1];
        }
    }
    for (int i = 0; i < N; i++) fMax[i][1] = A[i];
    for (int l = 2; l <= N; l++) {
        for (int i = 0; i+l <= N; i++) {
            fMax[i][l] = max(fRange[i][l], max(fMax[i][l-1], fMax[i+1][l-1]));
        }
    }
    
    scanf("%d", &Q);
    while (Q--) {
        int l, r;
        scanf("%d %d", &l, &r); l--; r--;
        printf("%d\n", fMax[l][r-l+1]);
    }
    
    return 0;
}