#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 105000

int N, subTreeSize[MAXN];
vector<int> graph[MAXN];

int dfsSize(int u, int p) {
    subTreeSize[u] = 1;
    for (int v: graph[u]) if (v != p) subTreeSize[u] += dfsSize(v, u);
    return subTreeSize[u];
}

int maxEven(int u, int p, int parentSize) {
    int sz = subTreeSize[u] + parentSize;
    int ans = 0;
    assert(sz % 2 == 0);
    for (int v: graph[u]) {
        if (v == p) continue;
        if (subTreeSize[v] % 2) {
            ans += maxEven(v, u, sz - subTreeSize[v]);
        } else {
            ans += 1 + maxEven(v, u, 0);
        }
    }
    return ans;
}

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N-1; i++) {
        int u,v;
        scanf("%d %d", &u, &v); u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    if (N % 2) {
        printf("-1\n");
        return 0;
    } 
    
    dfsSize(0, -1);
    printf("%d\n", maxEven(0, -1, 0));
    
    return 0;
}