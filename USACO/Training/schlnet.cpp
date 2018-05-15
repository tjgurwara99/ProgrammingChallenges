/*
ID: basimkh1
PROG: schlnet
LANG: C++11
*/
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define MAXN 200

int N;
vector<int> children[MAXN], parents[MAXN];

int countDominator(vector<int>* graph) {
    
    bool connected[MAXN][MAXN];
    int D[MAXN], dominated[MAXN];
    
    for (int i = 1; i <= N; i++) {
        D[i] = dominated[i] = false;
        for (int j = 1; j <= N; j++) connected[i][j] = false;
        for (int j : graph[i]) connected[i][j] = true;
    }
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (connected[i][k] && connected[k][j]) {
                    connected[i][j] = true;
                }
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (dominated[i]) continue;
        for (int j = 1; j <= N; j++) {
            if (connected[i][j]) {
                D[j] = false;
                dominated[j] = true;
            }
        }
        D[i] = true;
    }
    
    int ret = 0;
    for (int i = 1; i <= N; i++) if (D[i]) ++ret;
    return ret;
}

bool seen[MAXN];
void dfs(int n) {
    if (seen[n]) return;
    seen[n] = true;
    for (int j: children[n]) dfs(j);
}

int main() {
    
    freopen("schlnet.in", "r", stdin); freopen("schlnet.out", "w", stdout);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a;
        while (cin >> a, a) {
            children[i].push_back(a);
            parents[a].push_back(i);
        }
    }
    
    int dom = countDominator(children), codom = countDominator(parents);
    bool fullyConnected = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) seen[j] = false;
        dfs(i);
        for (int j = 1; j <= N; j++) fullyConnected &= seen[j];
        if (!fullyConnected) break;
    }
    
    cout << dom << "\n";
    cout << (fullyConnected ? 0 : max(dom, codom)) << "\n";
    
    return 0;
}