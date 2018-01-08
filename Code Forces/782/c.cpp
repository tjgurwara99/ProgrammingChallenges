#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 200001

int N;
vector<int> E[MAXN];
int colour[MAXN];
bool visited[MAXN];
int maxColour = 0;

void dfs(int node, int col, int pCol) {
    visited[node] = true;
    colour[node] = col;
    maxColour = max(maxColour, colour[node]);
    int currentColour = 1;
    for (int i = 0; i < (int)E[node].size(); i++) {
        if (!visited[E[node][i]]) {
            while (currentColour == col || currentColour == pCol) currentColour++;
            dfs(E[node][i], currentColour, col);
            currentColour++;
        }
    }
}

int main() {

    scanf("%d", &N);

    for (int i = 0; i < N-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    dfs(0, 1, 0);

    printf("%d\n", maxColour);
    for (int i = 0; i < N; i++) {
        printf("%d", colour[i]);
        if (i != N-1) printf(" ");
    }
    printf("\n");

    return 0;
}
