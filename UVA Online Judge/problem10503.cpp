#include <cstdio>

int N, M, ends[2][2], A[20][2];
bool used[20];

bool solve(int pos, int prev) {
    if (pos == N) return prev == ends[1][0];
    for (int i = 0; i < M; i++) {
        if (used[i]) continue;
        used[i] = true;
        if (prev == A[i][0] && solve(pos+1, A[i][1])) return true;
        if (prev == A[i][1] && solve(pos+1, A[i][0])) return true;
        used[i] = false;
    }
    return false;
}

int main() {
    while (scanf("%d", &N), N) {
        scanf("%d", &M);
        scanf("%d %d", &ends[0][0], &ends[0][1]);
        scanf("%d %d", &ends[1][0], &ends[1][1]);
        for (int i = 0; i < M; i++) scanf("%d %d", &A[i][0], &A[i][1]);
        for (int i = 0; i < M; i++) used[i] = false;
        printf(solve(0, ends[0][1])  ? "YES\n" : "NO\n");
    }
    return 0;
}