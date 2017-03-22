#include <cstdio>
using namespace std;

int R, C;
bool grid[257][257];

void readInput() {
    char temp[300];
    scanf("%d %d", &R, &C);

    for (int r = 0; r < R; r++) {
        scanf("%s", temp);
        for (int c = 0; c < C; c++) grid[r][c] = temp[c] == 'S';
    }
}

int DP[257][257][257];

int main() {

    readInput();

    int totalCount = 0;


    return 0;
}
