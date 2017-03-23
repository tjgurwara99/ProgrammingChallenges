#include <cstdio>
#include <algorithm>
using namespace std;

int R, C;
bool grid[257][257];
int DP[257][257];

int main() {

    char temp[300];
    scanf("%d %d", &R, &C);

    for (int r = 0; r < R; r++) {
        scanf("%s", temp);
        for (int c = 0; c < C; c++) grid[r][c] = temp[c] == 'S';
    }

    int totalCount = 0;
    
    for (int r = R-1; r >= 0; r--) {
        for (int c = C-1; c >= 0; c--) {
            if (!grid[r][c]) continue;
            DP[r][c] = 1 + min(DP[r+1][c], min(DP[r][c+1], DP[r+1][c+1]));
            totalCount += DP[r][c]-1;
        }
    }
    
    printf("%d\n", totalCount);

    return 0;
}
