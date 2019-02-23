#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXN 200000
#define MOD 1000000007

ll gcd(ll a, ll b, ll& x, ll& y) {
  x = 1; y = 0;
  ll m = 0, n = 1;
  while (b) {
    ll q = a/b;
    ll r = a-q*b;
    a = b;
    b = r;
    ll oldM = m;
    ll oldN = n;
    m = x - q*m;
    n = y - q*n;
    x = oldM;
    y = oldN;
  }
  return a;
}

ll modInv(ll x) {
  ll a, b;
  gcd(x, MOD, a, b);
  a %= MOD;
  if (a < 0) a += MOD;
  return a;
}

ll fact[MAXN];
string S;
ll N, A[MAXN];
ll typeCount[60];
ll modInvCount[60];

ll bigDP[101000][52];
bool bigPos[101000];

ll DP[60][60];

inline ll solve(ll typeA, ll typeB) {
  ll base = ...;

  if (typeA == typeB) {
    return (base * bigDP[N/2 - typeCount[typeA]][typeA]) % MOD;
  }


}

inline ll enemType(char c) {
  if (c >= 'A' && c <= 'Z') return c-'A';
  return 26+(c-'a');
}

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  fact[0] = 1;
  for (int i = 1; i < MAXN; i++) fact[i] = (i * fact[i-1]) % MOD;

  cin >> S;
  N = (ll)S.size();
  for (int i = 0; i < N; i++) {
    A[i] = enemType(S[i]);
    typeCount[A[i]]++;
  }
  for (int i = 0; i < 52; i++) {
    modInvCount[i] = modInv(fact[typeCount[i]]);
  }

  bigPos[0] = 1;
  for (int i = 0; i < 52; i++) {
    for (int j = N; j >= typeCount[i]; j--) {
      if (!bigPos[j-typeCount[i]) continue;
      for (int k = 0; k < 52; k++) {
        bigDP[j][k] += bigDP[j-typeCount[i]][k];
      }
      bigDP[j][i] += bigPos[j - typeCount[i]];
      bigPos[j] += bigPos[j - typeCount[i]];
    } 
  }

  for (int i = 0; i < 52; i++) {
    for (int j = 0; j < 52; j++) DP[i][j] = -1;
  }

  int Q;
  while (Q--) {
    int x, y;
    cin >> x >> y;
    ll a = A[x-1], b = A[y-1];
    if (a > b) swap(a,b);
    if (DP[a][b] == -1) DP[a][b] = solve(a,b);
    cout << DP[a][b] << "\n";
  }

  return 0;
}
