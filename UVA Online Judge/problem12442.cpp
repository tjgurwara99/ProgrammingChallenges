#include <cstdio>
int N, next[50000];
bool seen[50000];

int dfs(int u) {
    seen[u] = true;
    int ans = seen[next[u]] ? 1 :  1 + dfs(next[u]);
    seen[u] = false;
    return ans;
}

int main() {

    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            next[u-1] = v-1;
        }
        int maxAns = -1, maxIdx = -1;
        for (int i = 0; i < N; i++) {
            int ans = dfs(i);
            if (ans > maxAns) {
                maxIdx = i;
                maxAns = ans;
            }
        }
        printf("Case %d: %d\n", t, maxIdx+1);
    }

    return 0;
}
