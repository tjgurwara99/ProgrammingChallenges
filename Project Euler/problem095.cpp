#include <cstdio>
using namespace std;

#define LIM 1000000
#define ll long long

int nextNum[LIM+1];
int seen[LIM+1];

inline int divisorSum(int n) {
    int total = 1;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            total += i;
            if (i*i != n) total += n/i;
        }
    }
    return total;
}

int main() {
    for (int i = 1; i <= LIM; i++) nextNum[i] = divisorSum(i);

    int maxChainLength = 0;

    for (int i = 1; i <= LIM; i++) {
        if (seen[i] != 0) continue;
        int num = i, chainLength = i;

        while (num <= LIM && seen[num] < i) {
            seen[num] = chainLength++;
            num = nextNum[num];
        }
        if (num > LIM) break;

        int l = chainLength - seen[num];
        if (l > maxChainLength) {
            maxChainLength = l;
            printf("%d: %d\n", num, l);
        }
    }

    return 0;
}
