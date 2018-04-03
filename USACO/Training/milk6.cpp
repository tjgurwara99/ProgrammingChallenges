/*
ID: basimkh1
PROG: milk6
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 50
#define MAXM 2000
#define ll long long

int N, M, prevNode[MAXN], edges[MAXM][3];
ll capacity[MAXN][MAXN];
bool edgeRemoved[MAXM];

void fillCapacity() {
    
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) capacity[i][j] = 0;
    
    for (int i = 0; i < M; i++) {
        if (!edgeRemoved[i]) {
            capacity[edges[i][0]][edges[i][1]] += (MAXM + 1LL) * edges[i][2] + 1;
        }
    }
}

ll maxFlow() {
    
    ll totalFlow = 0;
    
    while (true) {
        
        queue<int> bfs;
        for (int i = 1; i <= N; i++) prevNode[i] = 0;
        bfs.push(1);
        
        while (!bfs.empty()) {
            int next = bfs.front();
            bfs.pop();
            
            for (int i = 1; i <= N; i++) {
                if (!prevNode[i] && capacity[next][i]) {
                    prevNode[i] = next;
                    bfs.push(i);
                }
            }
        }
        
        if (!prevNode[N]) break;
        
        ll flow = capacity[prevNode[N]][N];
        for (int node = N; node != 1; node = prevNode[node]) {
            flow = min(flow, capacity[prevNode[node]][node]);
        }
        for (int node = N; node != 1; node = prevNode[node]) {
            capacity[prevNode[node]][node] -= flow;
            capacity[node][prevNode[node]] += flow;
        }
        
        totalFlow += flow;
    }
    
    return totalFlow;
}

bool dfsEdges(int minEdge, int edgesLeft, ll totalFlow) {
    
    if (edgesLeft == 0) return totalFlow == 0;
    
    for (int e = minEdge; e < M; e++) {
        edgeRemoved[e] = true;
        fillCapacity();
        
        ll flow = maxFlow() / (MAXM + 1LL);
        //cout << e << " " << flow << " " << totalFlow << endl;
        if (totalFlow == flow + edges[e][2]) {
            if (dfsEdges(e+1, edgesLeft-1, flow)) return true;
        }
        
        edgeRemoved[e] = false;
    }
    
    return false;
}

int main() {
    
    freopen("milk6.in", "r", stdin);
    freopen("milk6.out", "w", stdout);
    
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    
    fillCapacity();
    ll totalFlow = maxFlow();
    ll flow = totalFlow / (MAXM + 1LL);
    int edges = (int)(totalFlow - flow * (MAXM + 1));
    
    dfsEdges(0, edges, flow);
    
    cout << flow << " " << edges << endl;
    for (int i = 0; i < M; i++) if (edgeRemoved[i]) cout << i+1 << endl;
    
    return 0;
}