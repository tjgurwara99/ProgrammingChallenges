/*
ID: basimkh1
PROG: hidden
LANG: C++11
*/
#include <cstdio>

int L;
char S[200000];

int main() {
    
    // freopen("hidden.in", "r", stdin); freopen("hidden.out", "w", stdout);
    
    scanf("%d %s", &L, S);
    
    int start = 0, currentStart = 1;
    for (int i = 1; i < 2*L; i++) {
        if (S[i % L] != S[(start + (i-currentStart)) % L]) {
            currentStart = i;
        }
        if (S[i % L] < S[(start + (i-currentStart)) % L]) {
            int temp = currentStart;
            currentStart = currentStart + (currentStart - start);
            start = temp;
        }
    }
    
    printf("%d %d\n", start, currentStart);
    
    return 0;
}