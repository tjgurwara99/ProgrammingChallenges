#include <cstdio>
#include <algorithm>
using namespace std;

#define NEGINF -100000

int M, N, cost[105], value[105], DP[10500][105][2];

int knapsack(int money, int idx, int useExtra) {

    if (idx > N) return NEGINF;

    if (money < 0) {
        if (useExtra) return NEGINF;
        useExtra = 1;
        money += 200;
        if (money < 0) return NEGINF;
    }
    if (idx == N) {
        if (useExtra && (M-money)+200 <= 2000) return NEGINF;
        return 0;
    }

    if (DP[money][idx][useExtra] == -1) {
        DP[money][idx][useExtra] = max(knapsack(money - cost[idx], idx+1, useExtra) + value[idx], knapsack(money, idx+1, useExtra));
    }

    return DP[money][idx][useExtra];
}

int main() {

    while (scanf("%d %d", &M, &N) != EOF) {
        for (int i = 0; i < N; i++) scanf("%d %d", &cost[i], &value[i]);
        for (int i = 0; i < M+200; i++) {
            for (int j = 0; j <= 100; j++) DP[i][j][0] = DP[i][j][1] = -1;
        }
        printf("%d\n", knapsack(M, 0, 0));
    }

    return 0;
}
