#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 350000
#define ll long long

int N;
ll W[MAXN];
vector<pair<int,ll> > adj[MAXN];

ll maxWithin[MAXN];
ll maxEndAt[MAXN];

void solve(int u, int p) {
  maxWithin[u] = maxEndAt[u] = W[u];

  ll fstVal = -1e9;
  ll sndVal = -1e9;
  for (auto e: adj[u]) {
    int v = e.first;
    ll c = e.second;
    if (v == p) continue;

    solve(v, u);
    maxWithin[u] = max(maxWithin[u], maxWithin[v]);

    ll val = maxEndAt[v] - c;

    if (val > fstVal) {
      sndVal = fstVal;
      fstVal = val;
    }
    else if (val > sndVal) {
      sndVal = val;
    }
  }

  maxWithin[u] = max(maxWithin[u], fstVal + sndVal + W[u]);
  maxEndAt[u] = max(maxEndAt[u], fstVal + W[u]);
  maxWithin[u] = max(maxWithin[u], maxEndAt[u]);
}

int main() {

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> W[i];

  for (int i = 1; i < N; i++) {
    int u,v;
    ll c;
    cin >> u >> v >> c;

    adj[u].push_back({v,c});
    adj[v].push_back({u,c});
  }

  solve(1, -1);
  cout << maxWithin[1] << endl;

  return 0;
}
