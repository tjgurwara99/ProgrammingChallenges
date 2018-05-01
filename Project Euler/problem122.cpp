#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* Slow and uses too much memory */
int m_bfs(int k) {
    queue<vector<int>> bfs;
    bfs.push({1});
    
    while (true) {
        vector<int>& current = bfs.front();
        int biggest = current[current.size()-1];
        if (biggest == k) return (int)current.size()-1;
        
        for (int i: current) {
            if (biggest + i > k) break;
            vector<int> newVec(current);
            newVec.push_back(biggest+i);
            bfs.push(newVec);
        }
        
        bfs.pop();
    }
    
    return -1;
}

int bestFound = 14, target, chain[14], chainCount;

void m_dfs(int minIdx) {
    if (chainCount >= bestFound) return;
    
    int biggest = chain[chainCount-1];
    if (biggest == target) {
        bestFound = chainCount;
        return;
    }
    
    if (biggest + biggest <= target) {
        chain[chainCount++] = biggest+biggest;
        m_dfs(0);
        chainCount--;
    }
    
    for (int i = chainCount-2; i >= minIdx; --i) {
        chain[chainCount++] = biggest+chain[i];
        m_dfs(i);
        chainCount--;
    }
}

int main() {
    
    int ans = 0;
    
    for (int i = 2; i <= 200; i++) {
        bestFound = 14;
        target = i;
        chain[0] = 1;
        chainCount = 1;
        m_dfs(0);
        
        ans += bestFound-1;
    }
    
    cout << ans << endl;
    
    return 0;
}