#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 200005

int N, M, A[MAXN], B[MAXN], P[MAXN];
bool bought[MAXN];
vector<int> colours[3];
int startIndex[3];

bool compareIndex(int a, int b) {
    return P[a] < P[b];
}

int main() {

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &P[i]);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i < N; i++) scanf("%d", &B[i]);
    scanf("%d", &M);

    for (int i = 0; i < N; i++) {
        if (A[i] == 1 || B[i] == 1) colours[0].push_back(i);
        if (A[i] == 2 || B[i] == 2) colours[1].push_back(i);
        if (A[i] == 3 || B[i] == 3) colours[2].push_back(i);
    }

    sort(colours[0].begin(), colours[0].end(), compareIndex);
    sort(colours[1].begin(), colours[1].end(), compareIndex);
    sort(colours[2].begin(), colours[2].end(), compareIndex);

    for (int i = 0; i < M; i++) {
        int c;
        scanf("%d", &c);
        c--;
        int& idx = startIndex[c];
        vector<int>& col = colours[c];

        while (idx < (int)col.size() && bought[col[idx]]) idx++;

        if (idx >= (int)col.size()) {
            printf("-1");
        } else {
            printf("%d", P[col[idx]]);
            bought[col[idx]] = true;
            idx++;
        }

        if (i == M-1) printf("\n"); else printf(" ");
    }

    return 0;
}
