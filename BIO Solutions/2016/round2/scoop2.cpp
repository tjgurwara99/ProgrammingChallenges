#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int N;
vector<int> graph[MAXN];

pair<int,int> deepestNode(int node, int parent) {
    int height = 0, child = node;
    for (int i = 0; i < (int)graph[node].size(); i++) {
        if (graph[node][i] != parent) {
            pair<int,int> res = deepestNode(graph[node][i], node);
            if (res.second+1 > height) {
                height = res.second+1;
                child = res.first;
            }
        }
    }
    return make_pair(child, height);
}

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int p1 = deepestNode(1, -1).first;
    int treeDiameter = deepestNode(p1, -1).second;
    
    int ans = 3 * (2*(N-1) - treeDiameter);
    printf("%d\n", ans);
    
    return 0;
}