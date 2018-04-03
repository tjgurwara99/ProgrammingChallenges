/*
ID: basimkh1
PROG: starry
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 200
#define FORWARD 0
#define LEFT 1
#define RIGHT 2

int directions[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1}}; // U,R,D,L
int leftDir[4][2] = { {-1, -1}, {-1, 0}, {0, 0}, {0, -1}};
int rightDir[4][2] = { {-1, 0}, {0, 0}, {0, -1}, {-1, -1}};

int W, H;
string grid[MAXN];
int cellComponent[MAXN][MAXN], componentCount[MAXN*MAXN], maxComponent;
int componentLabel[MAXN*MAXN], maxLabel;
vector<int> componentWalks[MAXN*MAXN];

void floodFill(int h, int w, int comp) {
    componentCount[comp]++;
    cellComponent[h][w] = comp;
    for (int h2 = max(0, h-1); h2 < H && h2 <= h+1; h2++) {
        for (int w2 = max(0, w-1); w2 < W && w2 <= w+1; w2++) {
            if (cellComponent[h2][w2] != comp && grid[h2][w2] == '1') {
                floodFill(h2, w2, comp);
            }
        }
    }
}

inline bool atPos(int h, int w, int comp) {
    if (h < 0 || h >= H || w < 0 || w >= W) return false;
    return cellComponent[h][w] == comp;
}

vector<int> walk(int h, int w, int d, int comp) {
    vector<int> moves;
    int r = h, c = w, sd = d;
    
    do {
        
        int lh = h + leftDir[d][0], lw = w + leftDir[d][1];
        int rh = h + rightDir[d][0], rw = w + rightDir[d][1];
        
        if (atPos(lh, lw, comp)) {
            moves.push_back(LEFT);
            d -= 1;
            if (d < 0) d += 4;
            
        } else if (!atPos(rh, rw, comp)) {
            moves.push_back(RIGHT);
            d += 1;
            if (d >= 4) d -= 4;
            
        } else {
            moves.push_back(FORWARD);
            h += directions[d][0];
            w += directions[d][1];
        }
        
    } while (r != h || c != w || d != sd);
    
    return moves;
}

bool compareWalks(int a, int b) {
    
    if (componentCount[a] != componentCount[b]) return false;
    if (componentWalks[a].size() != componentWalks[b].size()) return false;
    
    int n = (int)componentWalks[a].size();
    
    for (int start = 0; start < n; start++) {
        bool same = true;
        for (int offset = 0; offset < n; offset++) {
            int j = (start + offset) % n;
            if (componentWalks[a][offset] != componentWalks[b][j])  {
                same = false;
                break;
            } 
        }
        if (same) return true;
        
        same = true;
        for (int offset = 0; offset < n; offset++) {
            int j = (start - offset) % n;
            if (j < 0) j += n;
            
            if (componentWalks[a][offset] != componentWalks[b][j]) {
                same = false;
                break;
            } 
        }
        
        if (same) return true;
    }
    
    return false;
}

int main() {
    
    freopen("starry.in", "r", stdin);
    freopen("starry.out", "w", stdout);
    
    cin >> W >> H;
    
    for (int h = 0; h < H; h++) cin >> grid[h];
    
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
    
            if (grid[h][w] == '0') continue;
            
            if (!cellComponent[h][w]) {
                floodFill(h, w, ++maxComponent);
                componentWalks[maxComponent] = walk(h, w, 0, maxComponent);
                for (int c = 1; c < maxComponent; c++) {
                    if (compareWalks(c, maxComponent)) {
                        componentLabel[maxComponent] = componentLabel[c];
                        break;
                    }
                }
                
                if (!componentLabel[maxComponent]) {
                    componentLabel[maxComponent] = ++maxLabel;
                }
            }
            
            grid[h][w] = 'a' + (componentLabel[cellComponent[h][w]] - 1);
        }
    }
    
    for (int h = 0; h < H; h++) cout << grid[h] << endl;
    
    return 0;
}