/*
ID: basimkh1
PROG: telecow
LANG: C++11
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 105
#define INF 100000

int N, M, c1, c2;
int capacity[2*MAXN][2*MAXN], residual[2*MAXN][2*MAXN];
int prevBFS[2*MAXN];

inline int maxFlow() {
    
    int total = 0;
    
    for (int i = 0; i < 2*N; i++) {
        for (int j = 0; j < 2*N; j++) {
            residual[i][j] = capacity[i][j];
        }
    }
    
    while (true) {
        
        int s = 2*c1+1, t = 2*c2;
        
        for (int i = 0; i < 2*N; i++) prevBFS[i] = -1;
        
        vector<int> bfs;
        bfs.push_back(s);
        prevBFS[s] = s;
        
        for (int i = 0; i < (int)bfs.size(); i++) {
            int u = bfs[i];
            for (int v = 0; v < 2*N; v++) {
                if (prevBFS[v] == -1 && residual[u][v]) {
                    prevBFS[v] = u;
                    bfs.push_back(v);
                }
            }
        }
        
        if (prevBFS[t] == -1) break;
        
        int flow = residual[prevBFS[t]][t];
        for (int i = t; i != s; i = prevBFS[i]) {
            flow = min(flow, residual[prevBFS[i]][i]);
        }
        for (int i = t; i != s; i = prevBFS[i]) {
            residual[prevBFS[i]][i] -= flow;
            residual[i][prevBFS[i]] += flow;
        }
        total += flow;
    }
    
    return total;
}

int main() {
    
    freopen("telecow.in", "r", stdin); freopen("telecow.out", "w", stdout);
    
    scanf("%d %d %d %d", &N, &M, &c1, &c2);
    c1--; c2--;
    
    for (int i = 0; i < N; i++) capacity[2*i][2*i+1] = 1;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        capacity[2*u+1][2*v] = INF;
        capacity[2*v+1][2*u] = INF;
    }
    
    int totalFlow = maxFlow();
    printf("%d\n", totalFlow);
    
    for (int i = 0; i < N; i++) {
        if (i == c1 || i == c2) continue;
        
        capacity[2*i][2*i+1] = 0;
        int newFlow = maxFlow();
        
        if (newFlow + 1 == totalFlow) {
            totalFlow = newFlow;
            if (totalFlow) printf("%d ", i+1);
            else {
                printf("%d\n", i+1);
                break;
            }
        } else {
            capacity[2*i][2*i+1] = 1;
        }
    }
    
    return 0;
}