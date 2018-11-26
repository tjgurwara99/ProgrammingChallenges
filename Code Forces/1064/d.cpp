#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAXGRID (2001*2001)

struct node {
    int size = 0;
    vector<int> lefts, rights;
};

int nodeCount = 0;
node NODE[MAXGRID];

int N, M, startR, startC, X, Y;
bool blocked[2001][2001];
int nodeIdx[2001][2001];

char ln[5000];

int getNode(int r, int c);

int buildGraph(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M || blocked[r][c]) return -1;
    
    int v = ++nodeCount;
    NODE[v].size = 0;
    
    for (int i = c; i >= 0 && !blocked[r][i]; i--) {
        nodeIdx[r][i] = v;
        NODE[v].size++;
    }
    for (int i = c+1; i < M && !blocked[r][i]; i++) {
        nodeIdx[r][i] = v;
        NODE[v].size++;
    }
    for (int i = c; i >= 0 && !blocked[r][i]; i--) {
        if (r > 0 && !blocked[r-1][i]) NODE[v].lefts.push_back(getNode(r-1, i));
        if (r < N-1 && !blocked[r+1][i]) NODE[v].rights.push_back(getNode(r+1, i));
    }
    for (int i = c+1; i < M && !blocked[r][i]; i++) {
        if (r > 0 && !blocked[r-1][i]) NODE[v].lefts.push_back(getNode(r-1, i));
        if (r < N-1 && !blocked[r+1][i]) NODE[v].rights.push_back(getNode(r+1, i));
    }
    
    return v;
}

int getNode(int r, int c) {
    if (nodeIdx[r][c]) return nodeIdx[r][c];
    return buildGraph(r, c);
} 

bool reachable[MAXGRID];
pair<int,int> minLefts[MAXGRID];
pair<int,int> minRights[MAXGRID];

int main() {
    
    scanf("%d %d", &N, &M);
    scanf("%d %d", &startR, &startC);
    scanf("%d %d", &X, &Y);
    
    for (int r = 0; r < N; r++) {
        scanf(" %s", ln);
        for (int c = 0; c < M; c++) {
            blocked[r][c] = ln[c] == '*';
        }
    }
    
    startR--;
    startC--;
    
    buildGraph(startR, startC);
    
    queue<int> search;
    search.push(1);
    reachable[1] = true;
    int ans = NODE[1].size;
    
    while (!search.empty()) {
        int u = search.front();
        search.pop();
        
        auto newLeft = make_pair(minLefts[u].first + 1, minLefts[u].second);
        auto newRight = make_pair(minLefts[u].first, minLefts[u].second + 1);
        
        if (newLeft.first <= X) {
            for (int v: NODE[u].lefts) {
                if (!reachable[v] || newLeft < minLefts[v] || newLeft < minRights[v]) {
                    if (!reachable[v] || newLeft < minLefts[v]) minLefts[v] = newLeft;
                    if (!reachable[v] || newLeft < minRights[v]) minRights[v] = newLeft;
                    if (!reachable[v]) {
                        reachable[v] = true;
                        ans += NODE[v].size;
                    }
                    search.push(v);
                }
            }
        } 
        
        if (newRight.second <= Y) {
            for (int v: NODE[u].rights) {
                if (!reachable[v] || newRight < minLefts[v] || newRight < minRights[v]) {
                    if (!reachable[v] || newRight < minLefts[v]) minLefts[v] = newRight;
                    if (!reachable[v] || newRight < minRights[v]) minRights[v] = newRight;
                    if (!reachable[v]) {
                        reachable[v] = true;
                        ans += NODE[v].size;
                    }
                    search.push(v);
                }
            }
        } 
    }
    
    printf("%d\n", ans);
    
    return 0;
}