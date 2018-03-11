#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int N;
vector<int> graph[MAXN];

int treeHeight(int node, int parent) {
    int height = 0;
    for (int i = 0; i < (int)graph[node].size(); i++) {
        if (graph[node][i] != parent) {
            height = max(height, 1 + treeHeight(graph[node][i], node));
        }
    }
    return height;
}

int main() {
    
    int I;
    scanf("%d %d", &N, &I);
    
    for (int i = 0; i < N-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int ans = 3 * (2*(N-1) - treeHeight(I, -1));
    printf("%d\n", ans);
    
    return 0;
}