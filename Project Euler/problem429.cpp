#include <iostream>
using namespace std;

#define ll long long
#define MOD 1000000009
#define N 100000000

bool isComposite[N+1];

inline ll getPower(ll d) {
  int ans = 0;
  ll n = N;
  while (n) {
    n /= d;
    ans += n;
  }
  return ans;
}

inline ll pow(ll a, ll b) {
  ll ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = (ans*a) % MOD;
    a = (a*a) % MOD;
  }
  return ans;
}

int main() {
  ll ans = 1;

  for (ll i = 2; i <= N; i++) {
    if (isComposite[i]) continue;
    ll p = pow(i, getPower(i));
    ans *= (1 + (p*p) % MOD);
    ans %= MOD;
    for (ll j = i*i; j <= N; j+=i) isComposite[j] = true;
  }

  cout << ans << endl;

  return 0;
}
