#include <cstdio>
#include <cstdlib>

int R, C, pos[11][2], dist[11][11], N;
int mask, maskIdx[1024], DP[11][1024];

int tsp(int pos, int visited) {
    int toVisit = mask & (~visited);
    if (toVisit == 0) return dist[pos][0];

    if (DP[pos][visited] == -1) {
        DP[pos][visited] = 100000;
        while (toVisit) {
            int v = toVisit & (-toVisit);
            int ans = dist[pos][maskIdx[v]] + tsp(maskIdx[v], visited | v);
            if (ans < DP[pos][visited]) DP[pos][visited] = ans;
            toVisit -= v;
        }
    }

    return DP[pos][visited];
}

int main() {

    int T;
    scanf("%d", &T);

    for (int i = 0; i < 10; i++) maskIdx[1 << i] = i+1;

    while (T--) {
        scanf("%d %d", &R, &C);
        scanf("%d %d", &pos[0][0], &pos[0][1]);
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) scanf("%d %d", &pos[i][0], &pos[i][1]);

        for (int i = 0; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                dist[i][j] = dist[j][i] = abs(pos[i][0] - pos[j][0]) + abs(pos[i][1] - pos[j][1]);
            }
        }
        mask = (1 << N) - 1;
        for (int i = 0; i < 11; i++) for (int j = 0; j < 1024; j++) DP[i][j] = -1;

        printf("The shortest path has length %d\n", tsp(0, 0));
    }

    return 0;
}
