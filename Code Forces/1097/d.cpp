#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long
#define MOD 1000000007LL

ll pow(ll a, ll b) {
  if (b==0) return 1;
  ll x = pow(a,b/2);
  x = (x*x) % MOD;
  return (b % 2) ? (x*a)%MOD : x;
} 

ll modinv(ll x) { return pow(x,MOD-2); }

ll N, K;
ll DP[1000];
ll MODINVS[1000];
map<ll,ll> divProbs, temp;

void applyPrimePower(ll prime, int power) {
  for (int i = 0; i <= power; i++) {
    DP[i] = 0;
  }
  DP[power] = 1;
  for (int k = 1; k <= K; k++) {
    for (int i = 0; i <= power; i++) {
      DP[i]=(DP[i]*MODINVS[i+1])%MOD;
      for (int j = i+1; j <= power; j++) {
        DP[i]+=(DP[j]*MODINVS[j+1])%MOD;
      }
      DP[i]%=MOD;
    }
  }
  temp.clear();
  for (auto const& d: divProbs) {
    ll x = d.first;
    for (int i = 0; i <= power; i++) {
      if (temp.count(x)==0) temp[x]=0;
      temp[x] = (temp[x] + (d.second * DP[i])%MOD) % MOD;
      x *= prime;
    }
  }
  swap(divProbs, temp);
}

int main() {
  for (int i = 1; i < 1000; i++) MODINVS[i]=modinv(i);
  cin >> N >> K;
  divProbs[1] = 1;
  for (ll i = 2; i*i<=N; i++) {
    if (N % i) continue;
    int c = 0;
    while (N % i == 0) {
      N /= i;
      c++;
    }
    applyPrimePower(i,c);
  }
  if (N > 1) applyPrimePower(N,1);

  ll ans = 0;
  for (auto const &d: divProbs) {
    ans = (ans + ((d.first % MOD) * (d.second % MOD)) % MOD) % MOD;
  }
  if (ans < 0) ans += MOD;
  cout << ans << endl;

  return 0;
}
