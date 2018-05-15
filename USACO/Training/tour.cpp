/*
ID: basimkh1
PROG: tour
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i,n) FOR(i,0,n)
#define MAXN 200

int N, V, DP[MAXN][MAXN];
map<string, int> cities;
vector<int> graph[MAXN];
bool adjMat[MAXN][MAXN];

int main() {
    
    freopen("tour.in", "r", stdin); freopen("tour.out", "w", stdout);
    
    cin >> N >> V;
    REP(i, N) {
        string s;
        cin >> s;
        cities[s] = i;
    }
    
    REP(i, V) {
        string a, b;
        cin >> a >> b;
        int u = cities[a], v = cities[b];
        graph[min(u,v)].push_back(max(u,v));
        adjMat[u][v] = adjMat[v][u] = true;
    }
    
    DP[0][0] = 1;
    REP(i, N-1) {
        REP(j, N-1) {
            if (!DP[i][j]) continue;
            for (int k:graph[i]) if (k>j) DP[k][j] = max(DP[k][j], DP[i][j]+1);
            for (int k:graph[j]) if (k>i) DP[i][k] = max(DP[i][k], DP[i][j]+1);
        }
    }
    
    int ans = 1;
    REP(i, N) {
        if (!adjMat[i][N-1]) continue;
        FOR(j, i+1, N) {
            if (adjMat[j][N-1] && DP[i][j]) ans = max(ans, DP[i][j]+1);
        }
    }
    cout << ans << endl;
           
    return 0;
}