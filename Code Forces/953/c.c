#include <stdio.h>

int A[200000], N;

int main() {

    int i, valid = 1, stripLen = 0;

    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d", &A[i]);

    for (i = 0; i < N; i++) {
        if (A[i] != A[0]) break;
    }

    stripLen = i;
    valid = (N % stripLen) ? 0 : 1;
    for (; i < N; i++) {
        if (A[i] == A[i-stripLen]) {
            valid = 0;
            break;
        }
    }

    if (valid) printf("YES\n");
    else       printf("NO\n"); 
};
