#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000000
#define ll long long

bool isComposite[MAX];
vector<ll> primes;

// sum of k//2 for 1<=k<=n
inline ll upperBound(ll n) { return (n*n-n%2)/4; }

inline int phi(ll n) {
  return distance(primes.begin(), upper_bound(primes.begin(), primes.end(), n));
}

// count numbers <= n which are the sum of two primes (assuming n >= 3)
inline ll pairs(ll n) { return n/2-1+phi(n-2)-1; }

inline ll S(ll n) {
  ll p = n-1-phi(n); // no. not prime
  ll q = n-3-pairs(n); // no. not prime pair
  return upperBound(n) - p - q;
}

int main() {
  isComposite[0] = isComposite[1] = true;
  for (ll i = 2; i < MAX; i++) {
    if (isComposite[i]) continue;
    primes.push_back(i);
    for (ll j = i*i; j < MAX; j+=i) isComposite[j] = true;
  }

  ll a = 2;
  ll b = 3;
  ll ans = 3; // S(2)+S(3)
  for (int i = 5; i <= 44; i++) {
    ll c = a+b;
    a = b;
    b = c;
    ans += S(b);
  }
  cout << ans << endl;
  return 0;
}
