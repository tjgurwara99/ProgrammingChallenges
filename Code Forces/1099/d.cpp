#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXN 200000

ll N, P[MAXN], S[MAXN], A[MAXN];
vector<int> children[MAXN];

ll ans = 0;

void dfs(int u) {
  assert(S[u]>=0);
  for (int v: children[u]) {
    bool first = true;
    for (int w: children[v]) {
      ll d = S[w]-S[u];
      if (d<0) {
        ans = -1;
        return;
      }
      A[v] = first ? d : min(A[v],d);
      first = false;
    }
    ans += A[v];
    for (int w: children[v]) {
      ll d = S[w]-S[u];
      A[w] = d-A[v];
      ans += A[w];
      dfs(w);
      if (ans == -1) return;
    }
  }
}

int main() {
  cin >> N;
  FOR(i,2,N) {
    cin>>P[i];
    children[P[i]].push_back(i);
  }
  FOR(i,1,N) cin>>S[i];
  ans = S[1];
  dfs(1);
  cout << ans << endl;
  return 0;
}
