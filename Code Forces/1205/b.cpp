#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long
 
#define MAXN 200000
#define INF 1000000
 
int N;
ll A[MAXN];
vector<int> bits[64];
 
int depth[MAXN];
int parent[MAXN];
 
int cycle(int start) {
  queue<int> bfs;
  for (int i = 0; i < N; i++) depth[i] = -1;
  depth[start] = 0;
  bfs.push(start);
 
  int ans = INF;
  while (bfs.size() > 0) {
    int u = bfs.front();
    bfs.pop();
    for (int v = 0; v < N; v++) {
      if (v == u) continue;
      if (A[u] & A[v]) {
        if (depth[v]==0 && depth[u]>1) {
          ans = min(ans,depth[u]+1);
        }
        if (depth[v]>0 && parent[u]!=v) {
          ans = min(ans,depth[u]+depth[v]+1);
        }
        if (depth[v]<0) {
          depth[v] = depth[u]+1;
          parent[v] = u;
          bfs.push(v);
        }
      }
    }
  }
  return ans;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    for (int j = 0; j < 64; j++) {
      if (A[i] & (1LL << j)) {
        bits[j].push_back(i);
      }
    }
  }
  
  for (int i = 0; i < 64; i++) {
    if (bits[i].size() >= 3) {
      //cout << i << endl;
      cout << 3 << endl;
      return 0;
    }
  }
 
  int ans = INF;
  for (int i = 0; i < N; i++) {
    //cout << i << " " << cycle(i) << endl;
    ans = min(ans, cycle(i));
  }
  cout << (ans < INF ? ans : -1) << endl;
 
  return 0;
}
