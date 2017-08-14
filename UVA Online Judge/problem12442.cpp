#include <cstdio>

int main() {

    int T, N, next[60000], chainLength[60000], seen[60000];

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            next[u] = v;
            chainLength[i] = 0;
            seen[i] = 0;
        }

        int ans = 1;

        for (int i = 1; i <= N; i++) {
            if (seen[i]) continue;

            int j = i, count = 0;
            for (; !seen[j]; j = next[j], count++) seen[j] = i;

            count += chainLength[j];

            int k = i, upperCount = 0;
            for (; k != j; k = next[k], upperCount++) chainLength[k] = count - upperCount;

            if (seen[j] == i) {
                k = j;
                do {
                    chainLength[k] = count - upperCount;
                    k = next[k];
                } while (k != j);
            }

            if (chainLength[i] > chainLength[ans]) ans = i;
        }

        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
