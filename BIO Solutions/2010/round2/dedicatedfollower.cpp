#include <cstdio>
#include <vector>
using namespace std;

/*
SOLUTION:
From the problem we can deduce that all we need to do
is to count the number of disconnected cycles,
this will be equal to the number of edges that need to be
reveresed in order to make it acyclic.
*/

#define MAXN ((1<<16) + 1)

vector<int> adjList[MAXN];
bool visited[MAXN], inCurrentBranch[MAXN];

bool dfs(int c) { // Returns true if a cycle was found
    visited[c] = true;
    inCurrentBranch[c] = true;
    
    for (int i = 0; i < (int)adjList[c].size(); i++) {
        int n = adjList[c][i];
        
        if (visited[n] && !inCurrentBranch[n]) continue;
        
        if ( inCurrentBranch[n] || dfs(n)) {
            inCurrentBranch[c] = false;
            return true;
        }
    }
    
    inCurrentBranch[c] = false;
    return false;
}

int main() {
    
    int a, b;
    while (scanf("%d %d", &a, &b), a != -1) adjList[a].push_back(b);
    
    int cycleCount = 0;
    for (int i = 1; i < MAXN; i++) {
        if (!visited[i] && dfs(i)) cycleCount++;
    }
    
    printf("%d\n", cycleCount);
    
    return 0;
}