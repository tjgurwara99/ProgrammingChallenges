#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 200000

int N;
vector<int> graph[MAXN];
int dcount[2];

void dfs(int node, int depth, int parent) {
    dcount[depth % 2]++;
    for (int child : graph[node]) {
        if (child != parent) dfs(child, depth+1, node);
    }
}

int main() {

    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0, -1);

    cout << dcount[0]*dcount[1] - (N-1) << endl;

    return 0;
}
