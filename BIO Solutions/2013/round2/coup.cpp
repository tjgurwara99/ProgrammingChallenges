#include <bits/stdc++.h>
using namespace std;

#define MAXP 257
#define MAXN 1050

int N, P, W;
int indexOfCandidate[MAXP][MAXN], parentNode[MAXN], maxDepth = 0;
vector<int> graph[MAXN], nodesAtDepth[MAXN];

void dfs(int node, int parent, int depth) {
    maxDepth = max(maxDepth, depth);
    nodesAtDepth[depth].push_back(node);
    parentNode[node] = parent;
    
    for (int i = 0; i < (int)graph[node].size(); i++) {
        int child = graph[node][i];
        if (child != parent && parentNode[child] == 0) {
            dfs(child, node, depth+1);
        }
    }
}

int main() {
    
    scanf("%d %d %d", &N, &P, &W);
    
    for (int p = 0; p < P; p++) {
        for (int i = 0; i < N; i++) {
            int a;
            scanf("%d", &a);
            indexOfCandidate[p][a] = i;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            int iCount = 0, jCount = 0;
            
            for (int p = 0; p < P; p++) {
                if (indexOfCandidate[p][i] < indexOfCandidate[p][j]){
                    iCount++;
                } else {
                    jCount++;
                }
            }
            
            if (iCount > jCount) {
                graph[i].push_back(j);
            } else {
                graph[j].push_back(i);
            }
        }
    }
    
    dfs(W, W, 0);
    
    for (int i = 1; i <= N; i++) {
        if (parentNode[i] == 0) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    
    for (int i = maxDepth; i > 0; --i) {
        for (int j = 0; j < (int)nodesAtDepth[i].size(); j++) {
            int node = nodesAtDepth[i][j];
            printf("%d %d\n", node, parentNode[node]);
        }
    }
    
    return 0;
}