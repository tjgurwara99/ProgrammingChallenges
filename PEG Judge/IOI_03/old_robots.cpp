#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for (int i = a; i <= b; i++)

int DP[12][21][21][21][21];
int DP_dir[12][21][21][21][21];

int DIR[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} }; // n s e w

int dirNum(char c) {
    if (c == 'N') return 0;
    if (c == 'S') return 1;
    if (c == 'E') return 2;
    return 3;
}

struct grid {
    int R, C, G;
    bool blocked[20][20];
    int guardLength[10];
    
    int robot[2], guards[10][4]; // x y steps direction
    int oldRobot[2], oldGuards[10][4];
    
    void readInput() {
        scanf("%d %d", &R, &C);
        FOR(r,0,R-1) FOR(c,0,C-1) {
            char x;
            scanf(" %c", &x);
            blocked[r][c] = x == '#';
            if (x == 'X') {
                robot[0] = r;
                robot[1] = c;
            }
        }
        
        scanf("%d", &G);
        FOR(i,0,G-1) {
            char x;
            scanf("%d %d %d %c", &guards[i][0], &guards[i][1], &guardLength[i], &x);
            guards[i][0]--;
            guards[i][1]--;
            guards[i][2] = 0;
            guards[i][3] = dirNum(x);
        }
    }
    
    pair<bool,bool> forward(int d) {
        oldRobot[0] = robot[0];
        oldRobot[1] = robot[1];
        FOR(i,0,G-1) FOR(j,0,3) oldGuards[i][j] = guards[i][j];
        
        bool wasMoved = !solved();
        
        if (wasMoved) {
            robot[0] += DIR[d][0];
            robot[1] += DIR[d][1];
        }
        
        FOR(i,0,G-1) {
            guards[i][0] += DIR[guards[i][3]][0];
            guards[i][1] += DIR[guards[i][3]][1];
            guards[i][2]++;
            if (guards[i][2]+1 == guardLength[i]) {
                guards[i][2] = 0;
                guards[i][3] ^= 1;
            }
        }
        
        if (!solved() && blocked[robot[0]][robot[1]]) {
            robot[0] -= DIR[d][0];
            robot[1] -= DIR[d][1];
            wasMoved = false;
        }
        
        FOR(i,0,G-1) {
            if (robot[0] == guards[i][0] && robot[1] == guards[i][1]) {
                return make_pair(false, wasMoved);
            }
            if (
                (oldRobot[0] == guards[i][0] && oldRobot[1] == guards[i][1]) &&
                (robot[0] == oldGuards[i][0] && robot[1] == oldGuards[i][1])
                ) {
                return make_pair(false, wasMoved);
            }
        }
        
        return make_pair(true, wasMoved);
    }
    
    void back(int d, bool wasMoved) {
        if (wasMoved) {
            robot[0] -= DIR[d][0];
            robot[1] -= DIR[d][1];
        }
        FOR(i,0,G-1) {
            if (!guards[i][2]) {
                guards[i][3] ^= 1;
                guards[i][2] = guardLength[i] - 1;
            }
            guards[i][2]--;
            guards[i][0] -= DIR[guards[i][3]][0];
            guards[i][1] -= DIR[guards[i][3]][1];
        }
    }
    
    void print() {
        FOR(i,0,R-1) {
            FOR(j,0,C-1) printf("%c", blocked[i][j] ? '#' : ((robot[0] == i && robot[1] == j) ? 'X' : '.'));
            printf("\n");
        }
    }
    
    bool solved() {
        return robot[0] < 0 || robot[0] >= R || robot[1] < 0 || robot[1] >= C;
    }
};

grid grid1, grid2;
int currentTime;

int& getCache(int C[12][21][21][21][21]) {
    int ar = grid1.robot[0], ac = grid1.robot[1];
    int br = grid2.robot[0], bc = grid2.robot[1];
    if (grid1.solved()) {
        ar = grid1.R;
        ac = grid1.C;
    }
    if (grid2.solved()) {
        br = grid2.R;
        bc = grid2.C;
    }
    return C[currentTime % 12][ar][ac][br][bc];
}

int minTime() {
    
    if (grid1.solved() && grid2.solved()) {
        //printf("Found a solution!");
        return 0;
    }
    
    int& dp = getCache(DP);
    int& dp_dir = getCache(DP_dir);
    
    if (dp != -1) return dp;
    dp = 100000;
    dp_dir = -1;
    
    for (int d = 0; d < 4; d++) {
        pair<bool,bool> a = grid1.forward(d), b = grid2.forward(d);
        if (a.first && b.first) {
            currentTime++;
            int t2 = minTime() + 1;
            if (t2 < dp) {
                dp = t2;
                dp_dir = d;
            }
            currentTime--;
        }
        grid1.back(d, a.second);
        grid2.back(d, b.second);
    }
    
    return dp;
}

int main() {
    
    grid1.readInput();
    grid2.readInput();
    
    /*
    FOR(t,0,11) {
        FOR(i,0,grid1.R) FOR(j,0,grid1.C) {
            FOR(k,0,grid2.R) FOR(l,0,grid2.C) {
                DP[t][i][j][k][l] = -1;
            }
        }
    }
    
    int totalTime = minTime();
    
    if (totalTime > 10000) {
        printf("-1\n");
        return 0;
    }
    
    printf("%d\n", totalTime);
    while (!grid1.solved() || !grid2.solved()) {
        int d = getCache(DP_dir);
        printf("%c\n", "NSEW"[d]);
        //printf("Steps left %d\n", getCache(DP));
        grid1.forward(d);
        grid2.forward(d);
        currentTime++;
    }*/
    
    return 0;
}