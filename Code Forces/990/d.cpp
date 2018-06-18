#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 1001

int N, A, B;
bool adj[MAXN][MAXN];

void complement() {
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            adj[i][j] = adj[j][i] = !adj[i][j];
        }
    }
}

int main() {

    scanf("%d %d %d", &N, &A, &B);

    if (N == 1) {
        printf("YES\n0\n");
        return 0;
    }

    if (min(A,B) != 1 || (N < 4 && max(A,B) == 1)) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");

    int noEdges = N - max(A,B);
    //for (int i = 1; i <= noEdges; i++) adj[0][i] = adj[i][0] = true;
    for (int i = 0; i < noEdges; i++) {
        adj[i][i+1] = adj[i+1][i] = true;
    }

    if (A == 1) complement();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf(adj[i][j] ? "1" : "0");
        printf("\n");
    }

    return 0;
}
