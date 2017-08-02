/* Correct answer in 0.2s */
#include <cstdio>
#define LIM 1000000

int nextNum[LIM+1], seen[LIM+1];

int main() {

    nextNum[1] = 1;
    for (int d = 1; d+d <= LIM; d++) {
        for (int k = d+d; k <= LIM; k+=d) nextNum[k] += d;
    }

    int maxChainLength = 0, maxAns = -1;

    for (int i = 1; i <= LIM; i++) {
        int num = i, chainLength = 0;

        while (num <= LIM && seen[num] != i) {
            chainLength++;
            seen[num] = i;
            num = nextNum[num];
        }

        if (num == i && chainLength > maxChainLength) {
            maxChainLength = chainLength;
            maxAns = i;
        }
    }

    printf("%d: %d\n", maxAns, maxChainLength);

    return 0;
}
