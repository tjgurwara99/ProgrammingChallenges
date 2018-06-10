#include <cstdio>
#define FOR(i,a,n) for(int i=a; i<n; i++)
#define REP(i,n) FOR(i,0,n)

int n, prefix[101][101];
int main() {
    
    scanf("%d", &n);
    FOR(i,1,n+1) FOR(j,1,n+1) {
        scanf("%d", &prefix[i][j]);
        prefix[i][j] += prefix[i][j-1];
    }
    
    int ans = prefix[1][1];
    FOR(c1,1,n+1) FOR(c2,c1,n+1) {
        int total = 0;
        FOR(r,1,n+1) {
            if (total < 0) total = 0;
            total += prefix[r][c2] - prefix[r][c1-1];
            if (total > ans) ans = total;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}