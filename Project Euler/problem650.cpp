#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

/**
 * Exploit identity B(n) = n^n / n! * B(n-1)
 * Represent numbers as prime factor decomposition arrays
 *
 * */

#define ll long long

#define N 20000
#define MAX_PHI 3000 // loose upper bound on M ( phi(N) )
#define MOD 1000000007

bool isComposite[N+1];
vector<int> primes;

int M;
int B[MAX_PHI]; // B[i] is power of primes[i] in B(n) (in innner loop below)
int nPF[MAX_PHI]; // prime powers of n
int fact[MAX_PHI];  // prime powers of n!

void fillPrimeFactors(int n) {
  for (int i = 0; i < M; i++) nPF[i] = 0;

  int p = 0;
  while (primes[p]*primes[p] <= n) {
    while (n % primes[p] == 0) {
      n /= primes[p];
      nPF[p]++;
    }
    p++;
  }
  if (n > 1) {
    int idx = distance(primes.begin(), lower_bound(primes.begin(), primes.end(), n));
    nPF[idx]++;
  }
}

inline tuple<ll,ll,ll> egcd(ll a, ll b) {
  ll s = 1, t = 0;
  ll m = 0, n = 1;
  while (b) {
    ll oldA = a, q = a/b;
    a = b; b = oldA - q*b;

    ll oldS = s, oldT = t;
    s = m; t = n;
    m = oldS - q*m; n = oldT - q*n;
  }
  return make_tuple(a, s, t);
}

inline ll modInv(int n) {
  ll v = get<1>(egcd(n,MOD)) % MOD;
  if (v < 0) v += MOD;
  return v;
}

inline ll pow(ll a, int b) {
  ll ans = 1;
  ll c = a;
  for (; b; b >>=1) {
    if (b & 1) ans = (ans * c) % MOD;
    c = (c*c) % MOD;
  }
  return ans;
}

ll primeInvProd = 1;

// compute divisor sum of no. given by B (mod MOD)
ll D() { 
  ll p = 1;
  for (int i = 0; i < M; i++) {
    ll q = (pow(primes[i], B[i]+1) - 1) % MOD;
    if (q < 0) q += MOD;
    p = (p * q) % MOD;
  }
  return (primeInvProd * p) % MOD;
}

int main() {

  isComposite[0] = isComposite[1] = true;
  for (int i = 2; i <= N; i++) {
    if (isComposite[i]) continue;
    primes.push_back(i);
    primeInvProd = (primeInvProd * (i - 1)) % MOD;
    for (int j = i*i; j <= N; j+=i) isComposite[j] = true;
  }

  M = (int)primes.size();
  primeInvProd = modInv(primeInvProd);

  ll total = 1;
  for (int n = 2; n <= N; n++) {
    fillPrimeFactors(n);
    for (int i = 0; i < M; i++) fact[i] += nPF[i];
    for (int i = 0; i < M; i++) B[i] += n * nPF[i] - fact[i];
    total = (total + D()) % MOD;
  }
  cout << total << endl;

  return 0;
}
