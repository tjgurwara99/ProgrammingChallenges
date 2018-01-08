#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 300000

char T[MAXN], P[MAXN];
int N, K, A[MAXN];
bool available[MAXN];

bool validUntil(int p) {
    for (int i = 0; i < N; i++) available[i] = true;
    for (int i = 0; i < p; i++) available[A[i]-1] = false;

    int pidx = 0;

    for (int i = 0; i < N; i++) {
        if (available[i] && T[i] == P[pidx]) {
            pidx++;
            if (pidx == K) break;
        }
    }

    return pidx == K;
}

int main() {

    scanf("%s", T);
    scanf("%s", P);

    N = strlen(T);
    K = strlen(P);

    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    int pos = 0;
    int len = N+1; 

    while (len > 1) {
        int step = len / 2;
        int newPos = pos + step;
        if (validUntil(newPos)) {
            pos = newPos;
            len -= step;
        } else {
            len = step;
        }
    }

    printf("%d\n", pos);

    return 0;
}
