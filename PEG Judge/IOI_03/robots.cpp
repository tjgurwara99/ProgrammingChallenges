#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define MAXSTATE (12 * 21 * 21 * 21 * 21)

int lastState[MAXSTATE], lastDir[MAXSTATE];

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
    int robot[2], guards[10][4]; // x y length direction
    int guardPos[10][2], oldGuardPos[10][2];
    
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
            scanf("%d %d %d %c", &guards[i][0], &guards[i][1], &guards[i][2], &x);
            guards[i][0]--;
            guards[i][1]--;
            guards[i][2] = (guards[i][2] - 1) * 2;
            guards[i][3] = dirNum(x);
        }
    }
    
    void calculateGuardPos(int t) {
        FOR(i,0,G-1) {
            oldGuardPos[i][0] = guardPos[i][0];
            oldGuardPos[i][1] = guardPos[i][1];
            int nt = t % guards[i][2];
            nt = min(nt, guards[i][2] - nt);
            guardPos[i][0] = guards[i][0] + DIR[guards[i][3]][0] * nt;
            guardPos[i][1] = guards[i][1] + DIR[guards[i][3]][1] * nt;
        }
    }
    
    void advance(int& r, int& c, int d) {
        if (r == 20) return;
        r += DIR[d][0];
        c += DIR[d][1];
        if (r < 0 || r >= R || c < 0 || c >= C) r = c = 20;
        else if (blocked[r][c]) {
            r -= DIR[d][0];
            c -= DIR[d][1];
        }
    }
    
    bool valid(int rr, int rc, int d) {
        if (rr == 20) return true;
        int r = rr, c = rc;
        advance(r, c, d);
        FOR(i,0,G-1) {
            if (r==guardPos[i][0] && c==guardPos[i][1]) return false;
            if (r==oldGuardPos[i][0] && c==oldGuardPos[i][1]
            && rr==guardPos[i][0] && rc==guardPos[i][1]) return false;
        }
        return true;
    }
    
    void print() {
        FOR(i,0,R-1) {
            FOR(j,0,C-1) printf("%c", blocked[i][j] ? '#' : ((robot[0] == i && robot[1] == j) ? 'X' : '.'));
            printf("\n");
        }
    }
};
    
grid grid1, grid2;

int getState(int t, int ar, int ac, int br, int bc) {
    int st = ar;
    st = st*21+ac;
    st = st*21+br;
    st = st*21+bc;
    st = st*12+(t % 12);
    return st;
}

void expandState(int st, int& ar, int& ac, int& br, int& bc) {
    st /= 12;
    bc = st % 21;
    st /= 21;
    br = st % 21;
    st /= 21;
    ac = st % 21;
    st /= 21;
    ar = st;
}

int bfs() {
    
    vector<int> search, newNodes;
    int ar, ac, br, bc;
    
    search.push_back(getState(0, grid1.robot[0], grid1.robot[1], grid2.robot[0], grid2.robot[1]));
    lastState[search[0]] = -1;
    
    grid1.calculateGuardPos(0);
    grid2.calculateGuardPos(0);
    
    for (int t = 0; t <= 10000; t++) {
        grid1.calculateGuardPos(t+1);
        grid2.calculateGuardPos(t+1);
        for (int st: search) {
            for (int d = 0; d < 4; d++) {
                expandState(st, ar, ac, br, bc);
                if (ar == 20 && br == 20) return st;
                if (grid1.valid(ar, ac, d) && grid2.valid(br, bc, d)) {
                    grid1.advance(ar, ac, d);
                    grid2.advance(br, bc, d);
                    int newSt = getState(t+1, ar, ac, br, bc);
                    if (!lastState[newSt]) {
                        lastState[newSt] = st;
                        lastDir[newSt] = d;
                        newNodes.push_back(newSt);
                    }
                }
            }
        }
        swap(search, newNodes);
        newNodes.clear();
    }
    return -1;
}

int main() {
    
    grid1.readInput();
    grid2.readInput();
    
    int finalState = bfs();
    if (finalState == -1) {
        printf("-1\n");
        return 0;
    }
    
    vector<int> steps;
    while (lastState[finalState] != -1) {
        steps.push_back(lastDir[finalState]);
        finalState = lastState[finalState];
    }
    
    printf("%d\n", (int)steps.size());
    for (int i = (int)steps.size()-1; i >= 0; i--) printf("%c\n", "NSEW"[steps[i]]);
    
    return 0;
}