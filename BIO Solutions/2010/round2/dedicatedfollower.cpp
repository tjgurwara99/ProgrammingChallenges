#include <cstdio>
#include <vector>
using namespace std;

/*

SOLUTION:

From the problem we can deduce that all we need to do
is to count the number of cycles in this directed graph,
this will be equal to the number of edges that need to be
reveresed in order to make it acyclic.

*/

#define MAXN 1<<16 + 1

vector<int> adjList[MAXN];

void dfs() {
    
}

int main() {
    
    int a, b;
    while (scanf("%d %d", &a, &b), a != -1)  adjList[a].push_back(b);
    
    
    
    
    return 0;
}