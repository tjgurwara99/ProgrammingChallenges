#include <bits/stdc++.h>
using namespace std;

const int padding = 20;
const int gridSize = 5;
const int gridDim = 2*padding+gridSize;

int grid[gridDim][gridDim];
#define GRID(r,c) grid[(r)+padding][(c)+padding]

void checkGrid(int r, int c) {
    if (GRID(r,c) >= 4) {
        GRID(r,c) -= 4;
        
        GRID(r+1,c)++;
        GRID(r-1,c)++;
        GRID(r,c+1)++;
        GRID(r,c-1)++;
        
        checkGrid(r+1,c);
        checkGrid(r-1,c);
        checkGrid(r,c+1);
        checkGrid(r,c-1);
    }
}

void printGrid() {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            printf("%d ", GRID(i,j));
        }
        printf("\n");
    }
}

void run(int p, int n, int s, int *S) {
    
    for (int i = 0; i < gridDim; i++) {
        for (int j = 0; j < gridDim; j++) {
            grid[i][j] = 0;
        }
    }
    
    p -= 1;
    
    for (int i = 0; i < n; i++) {
        int r = p/gridSize, c = p%gridSize;
        GRID(r,c)++;
        checkGrid(r,c);
        
        p = (p + S[i % s]) % (gridSize * gridSize);
    }
}

int main() {
    
    int s, n, p, S[10];
    
    cin >> p >> s >> n;
    for (int i = 0; i < s; i++) cin >> S[i];
    
    run(p, n, s, S);
    printGrid();
    
    return 0;
}