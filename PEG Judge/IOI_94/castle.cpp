#include <cstdio>

int direction[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

int N, M, A[50][50], parent[2500], sz[2500], compCount, maxSz = 1;

int root(int p) { return (parent[p] == p) ? p : (parent[p] = root(parent[p])); }

void join(int a, int b) {
    int p = root(a), q = root(b);
    if (p == q) return;
    if (sz[p] < sz[q]) {
        int c = p;
        p = q;
        q = c;
    }
    sz[p] += sz[q];
    parent[q] = p;
    compCount--;
    if (sz[p] > maxSz) maxSz = sz[p];
}

int main() {

    scanf("%d %d", &M, &N);

    compCount = N*M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            parent[i*M+j] = i*M+j; 
            sz[i*M+j] = 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
            for (int d = 0; d < 4; d++) {
                if (A[i][j] & (1 << d)) continue;
                int i2 = i+direction[d][0], j2 = j+direction[d][1];
                join(i*M+j, i2*M+j2);
            }
        }
    }

    printf("%d\n%d\n", compCount, maxSz);

    int maxDouble = maxSz, wallI, wallJ;
    bool isNorth;

    for (int j = M-1; j >= 0; j--) {
        for (int i = 0; i < N; i++) {
            if ((A[i][j] & 4) && j+1 < M && root(i*M+j) != root(i*M+j+1)) {
                int a = sz[root(i*M+j)] + sz[root(i*M+j+1)];
                if (a >= maxDouble) {
                    maxDouble = a;
                    wallI = i;
                    wallJ = j;
                    isNorth = false;
                }
            }
            if ((A[i][j] & 2) && i > 0 && root(i*M+j) != root((i-1)*M+j)) {
                int a = sz[root(i*M+j)] + sz[root((i-1)*M+j)];
                if (a >= maxDouble) {
                    maxDouble = a;
                    wallI = i;
                    wallJ = j;
                    isNorth = true;
                }
            }
        }
    }

    printf("%d\n%d %d %c\n", maxDouble, wallI+1, wallJ+1, isNorth ? 'N' : 'E');

    return 0;
}
