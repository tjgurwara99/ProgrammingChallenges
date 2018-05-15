/*
ID: basimkh1
PROG: bigbrn
LANG: C++11
*/
#include <cstdio>

#define min(x, y) (((x) < (y)) ? (x) : (y))

#define MAXN 1002

int N, T;
bool grid[MAXN][MAXN];
int DP[MAXN][MAXN];

int main() {
    
    freopen("bigbrn.in", "r", stdin); freopen("bigbrn.out", "w", stdout);
    
    scanf("%d %d", &N, &T);
    
    for (int i = 0; i < T; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        grid[r][c] = true;
    }
    
    int ans = 0;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (!grid[r][c]) {
                DP[r][c] = 1 + min(DP[r-1][c], min(DP[r-1][c-1], DP[r][c-1]));
                if (DP[r][c] > ans) ans = DP[r][c];
            }
        }
    }
    printf("%d\n", ans);
    
    return 0;
}