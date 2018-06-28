#include <cstdio>

int N, A[10][10];

int solve(int row, int mask) {
    if (row == N) return 0;
    int ans = 1000000;
    for (int i = 0; i < N; i++) {
        if (!(mask & (1 << i))) {
            int a = A[row][i] + solve(row+1, mask | (1 << i));
            if (a < ans) ans = a;
        }
    }
    return ans;
}

int main() {
    
    int T;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
        printf("%d\n", solve(0, 0));
    }
}