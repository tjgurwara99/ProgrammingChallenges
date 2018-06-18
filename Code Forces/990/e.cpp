#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 2000000
#define MAXK 2000000

int N, M, K, S[MAXN], A[MAXK], prevFree[MAXN];

int main() {

    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < N; i++) prevFree[i] = i;

    for (int i = 0; i < M; i++) scanf("%d", &S[i]);
    sort(S, S+M);
    for (int i = 0; i < M; i++) {
        if (S[i] == 0) {
            prevFree[0] = -1;
            break;
        } else {
            prevFree[S[i]] = prevFree[S[i]-1];
        }
    }

    for (int i = 0; i < K; i++) {
        int cost;
        scanf("%d", &cost);

        bool valid = true;
        int ans = 1, lastPos = 0;

        for (int pos = K; pos < N; pos += K) {
            while (pos > lastPos)
        }
    }

    return 0;
}
