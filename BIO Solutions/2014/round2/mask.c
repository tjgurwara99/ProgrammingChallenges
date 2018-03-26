#include <string.h>
#include <stdio.h>

#define MAXN 1234567
#define max(a,b) (((a) > (b)) ? (a):(b))

char S[MAXN];
int N[MAXN];

int main() {
    
    int M, idx, maxIdx;
    
    scanf("%s", S);
    M = strlen(S);
    
    for (idx = 0; idx < M; idx++) N[idx] = S[M-idx-1]-'0';
    
    idx = maxIdx = M-1;
    while (idx >= 0) {
        if (N[idx] && N[idx+1]) {
            N[idx]--;
            N[idx+1]--;
            N[idx+2]++;
            idx += 2;
        } else if (N[idx] == 2) {
            if (idx) N[max(idx-2, 0)]++;
            N[idx] = 0;
            N[idx+1]++;
            idx += 1;
        } else {
            idx--;
        }
        if (idx > maxIdx) maxIdx = idx;
    }
    
    for (; maxIdx >= 0; maxIdx--) printf(N[maxIdx] ? "1" : "0");
    printf("\n");
    
    return 0;
}