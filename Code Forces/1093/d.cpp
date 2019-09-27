#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
#define MOD 998244353
#define MAXN 500000

int N, M;
vector<int> adj[MAXN];

ll pow2[MAXN];

int seen[MAXN];
int compCount[2];

bool dfs(int u, int even) { // even, odd dists, return if fail
  
  if (seen[u] != -1 && seen[u] != even) {
    return true;
  } else if (seen[u] != -1) {
    return false;
  }

  seen[u] = even;
  compCount[even]++;
  for (int v: adj[u]) {
    if (dfs(v, 1-even)) return true;
  }

  return false;
}

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;

  pow2[0] = 1;
  for (int i = 1; i < MAXN; i++) pow2[i] = (pow2[i-1] << 1) % MOD;

  while (T--) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
      adj[i].clear();
      seen[i] = -1;
    }
    for (int m = 0; m < M; m++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    ll ans = 1;
    for (int i = 1; i <= N; i++) {
      if (seen[i] != -1) continue;
      compCount[0] = compCount[1] = 0;
      if (dfs(i, 0)) {
        ans = 0;
        break;
      } 
      ans *= (pow2[compCount[0]] + pow2[compCount[1]]) % MOD;
      ans %= MOD;
    }
    cout << ans << "\n";
  }

  return 0;
}
