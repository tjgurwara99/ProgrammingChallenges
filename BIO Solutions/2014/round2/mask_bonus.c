#include <string.h>
#include <stdio.h>

#define MAXN 1234567
#define max(a,b) (((a) > (b)) ? (a):(b))

char B[MAXN], F[MAXN];
int A[MAXN];

int main() {
    
    int M, idx, maxIdx, l_b, l_f;
    
    scanf("%s", B);
    scanf("%s", F);
    l_b = strlen(B);
    l_f = strlen(F);
    M = max(l_b, l_f);
    
    for (idx = 0; idx < l_b; idx++) A[l_b-idx-1] += B[idx]-'0';
    for (idx = 0; idx < l_f; idx++) A[l_f-idx-1] += F[idx]-'0';
    
    idx = maxIdx = M-1;
    while (idx >= 0) {
        if (A[idx] && A[idx+1]) {
            A[idx]--;
            A[idx+1]--;
            A[idx+2]++;
            idx += 2;
        } else if (A[idx] == 2) {
            if (idx) A[max(idx-2, 0)]++;
            A[idx] = 0;
            A[idx+1]++;
            idx += 1;
        } else {
            idx--;
        }
        if (idx > maxIdx) maxIdx = idx;
    }
    
    for (; maxIdx >= 0; maxIdx--) printf(A[maxIdx] ? "1" : "0");
    printf("\n");
    
    return 0;
}