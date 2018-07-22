#include <cstdio>
#include <cstring>

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define MAXN 200

int N, M, nodeCount;
bool graph[MAXN][MAXN];
char names[MAXN][10], x[10], y[10], buffer[100];

inline int find(const char* name) {
    FOR(i,0,nodeCount) if (!strcmp(name, names[i])) return i;
    return -1;
}

int main() {

    int t = 0;

    while (scanf("%d", &N), N) {

        nodeCount = 0;
        FOR(i,0,N) {
            int c;
            scanf("%d", &c);
            FOR(j,0,c) scanf(" %s", names[nodeCount+j]);
            FOR(j,0,c-1) graph[nodeCount+j][nodeCount+j+1] = true;
            nodeCount += c;
        }

        scanf("%d", &M);
        while (M--) {
            scanf(" %s %s", x, y);
            graph[find(x)][find(y)] = true;
        }

        FOR(k,0,nodeCount) FOR(i,0,nodeCount) FOR(j,0,nodeCount) graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);

        int ans = 0, bufferSize = 0;
        FOR(i,0,nodeCount) FOR(j,i+1,nodeCount) {
            if (!graph[i][j] && !graph[j][i]) {
                if (ans < 2) bufferSize += sprintf(buffer+bufferSize, "(%s,%s) ", names[i], names[j]);
                ++ans;
            }
        }

        if (ans) printf("Case %d, %d concurrent events:\n%s\n", ++t, ans, buffer);
        else     printf("Case %d, no concurrent events.\n", ++t);

        FOR(i,0,nodeCount) FOR(j,0,nodeCount) graph[i][j] = false;
    }

    return 0;
}