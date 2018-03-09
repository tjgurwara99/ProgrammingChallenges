#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int N, P[MAXN];
vector<int> graph[MAXN];
int depthCount[MAXN];

void dfs(int node, int depth) {
    depthCount[depth]++;
    for (int i = 0; i < (int)graph[node].size(); i++) {
        dfs(graph[node][i], depth+1);
    }
}

int main() {
    
    cin >> N;
    for (int i = 2; i <= N; i++) {
        cin >> P[i];
        graph[P[i]].push_back(i);
    }
    
    dfs(1, 0);
    
    int total = 0;
    for (int i = 0; i <= N; i++) {
        total += (depthCount[i] % 2);
    }
    
    cout << total << endl;
    
    return 0;
}