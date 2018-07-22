#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define INFINITY 100000

int P, R, peopleSeen;
char names[51][50], a[50], b[50];
int graph[51][51];

int find(char* name) {
    FOR(i,0,peopleSeen) if (!strcmp(names[i], name)) return i;
    strcpy(names[peopleSeen], name);
    return peopleSeen++;
}

int main() {
    int t = 0;
    while (scanf("%d %d", &P, &R), P) {
        FOR(i,0,P) FOR(j,0,P) graph[i][j] = INFINITY;
        FOR(i,0,P) graph[i][i] = 0;
        peopleSeen = 0;
        while (R--) {
            scanf(" %s %s", a, b);
            int x = find(a), y = find(b);
            graph[x][y] = graph[y][x] = 1;
        }

        FOR(k,0,P) FOR(i,0,P) FOR(j,0,P) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

        int ans = graph[0][0];
        FOR(i,0,P) FOR(j,0,P) ans = max(ans, graph[i][j]);

        if (ans == INFINITY) printf("Network %d: DISCONNECTED\n\n", ++t);
        else printf("Network %d: %d\n\n", ++t, ans);
    }

    return 0;
}