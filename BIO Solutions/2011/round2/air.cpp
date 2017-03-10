#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int W;
vector<pair<int,int>> graph[257];
int d1[257], d2[257];
priority_queue<pair<int,int>> Q; 

int main() {
    
    scanf("%d", &W);
    
    int a, b, weight;
    while (scanf("%d %d %d", &a, &b, &weight), a != -1) {
        graph[a].push_back(make_pair(b, weight));
        graph[b].push_back(make_pair(a, weight));
    }
    
    // Double dijkstra, expanding out the DP for both
    // the distances
    for (int i = 1; i <= W; i++) d1[i] = d2[i] = INT_MAX;
    
    d1[1] = 0;
    Q.push(make_pair(0, 1));
    
    while (!Q.empty()) {
        int w = -Q.top().first;
        int u = Q.top().second;
        Q.pop();
        
        if (w > d2[u]) continue;
        
        for (int i = 0; i < (int)graph[u].size(); i++) {
            int v = graph[u][i].first;
            int d = w + graph[u][i].second;
            
            if (d < d1[v]) {
                swap(d, d1[v]);
                Q.push(make_pair(-d1[v], v));
            }
            
            if (d > d1[v] && d < d2[v]) {
                d2[v] = d;
                Q.push(make_pair(-d2[v], v));
            }
        }
    }
    
    printf("%d\n", d2[W]);
    
    return 0;
}