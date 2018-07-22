#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N, M, P, store[20];
long long saving[20], dist[100][100], DP[100][1 << 13];
bool seen[100][1 << 13];

long long tsp(int pos, int mask) {
    if (!seen[pos][mask]) {
        seen[pos][mask] = true;
        DP[pos][mask] = -dist[pos][0];
        for (int i = 0; i < P; i++) {
            if (mask & (1 << i)) continue;
            long long a = saving[i] - dist[pos][store[i]] + tsp(store[i], mask | (1 << i));
            if (a > DP[pos][mask]) DP[pos][mask] = a;
        }
    }
    return DP[pos][mask];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) dist[i][j] = (long long)1e10;
            dist[i][i] = 0;
        }
        while (M--) {
            int a, b;
            double w;
            scanf("%d %d %lf", &a, &b, &w);
            dist[a][b] = dist[b][a] = min((long long)round(w * 100), dist[a][b]);
        }
        for (int k = 0; k <= N; k++) {
            for (int i = 0; i <= N; i++) {
                for (int j = 0; j <= N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        scanf("%d", &P);
        for (int i = 0; i < P; i++) {
            double w;
            scanf("%d %lf", &store[i], &w);
            saving[i] = (long long)round(w * 100);
        }
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < (1 << P); j++) seen[i][j] = false;
        }

        long long ans = tsp(0,0);
        if (ans > 0) printf("Daniel can save $%lld.%02lld\n", ans/100, ans%100);
        else printf("Don't leave the house\n");
    }

    return 0;
}