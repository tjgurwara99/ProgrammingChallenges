/*
ID: basimkh1
PROG: snail
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 200

int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int N;
bool grid[MAXN][MAXN], used[MAXN][MAXN];

int maxDistance(int r, int c, int d) {
    int dist = 0, maxSubDist = 0;
    
    while (!grid[r][c] && !used[r][c]) {
        dist++;
        used[r][c] = true;
        r += directions[d][0];
        c += directions[d][1];
    } 
    
    if (!used[r][c]) {
        r -= directions[d][0];
        c -= directions[d][1];
        for (int d2 = 0; d2 < 4; d2++) {
            int r2 = r + directions[d2][0], c2 = c + directions[d2][1];
            if (!grid[r2][c2] && !used[r2][c2]) {
                int subDist = maxDistance(r2, c2, d2);
                maxSubDist = max(maxSubDist, subDist);
            }
        }
        r += directions[d][0];
        c += directions[d][1];
    } 
    
    for (int i = 0; i < dist; i++) {
        r -= directions[d][0];
        c -= directions[d][1];
        used[r][c] = false;
    }
    
    return dist + maxSubDist;
}

int main() {
    
    freopen("snail.in", "r", stdin);
    freopen("snail.out", "w", stdout);
    
    int B;
    cin >> N >> B;
    
    for (int i = 1; i <= N; i++) {
        grid[0][i] = grid[N+1][i] = true;
        grid[i][0] = grid[i][N+1] = true;
    }
    
    while (B--) {
        string pos;
        cin >> pos;
        
        int c = (pos[0]-'A')+1;
        int r = stoi(pos.substr(1));
        grid[r][c] = true;
    }
    
    cout << max(maxDistance(1,1,0), maxDistance(1,1,2)) << endl;
    
    return 0;
}