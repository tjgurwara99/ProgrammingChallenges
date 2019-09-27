#include <iostream>
using namespace std;

#define ll long long

// lcm[i] = lcm(1,2,...,i)
ll lcm[33];

// count 1 < x < n where streak(x) >= s
ll S(int s, ll n) { return (n-2)/lcm[s]; }

ll P(int s, ll n) { return S(s,n) - S(s+1,n); }

inline ll gcd(ll a, ll b) {
  while (b) {
    ll c = a;
    a = b;
    b = c % b;
  }
  return a;
}

int main() {
  lcm[1] = 1;
  for (int i = 2; i <= 32; i++) lcm[i] = lcm[i-1] * (i / gcd(i, lcm[i-1]));

  ll ans = 0;
  for (int i = 1; i <= 31; i++) ans += P(i, 1LL << (i+i));
  cout << ans << endl;

  return 0;
}
