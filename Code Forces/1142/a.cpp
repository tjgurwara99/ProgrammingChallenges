#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

ll N, K, A, B;

inline ll gcd(ll a, ll b) {
  ll c;
  while (b) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

inline ll dist(ll a, ll b) {
  ll temp = (N*K+b-a) % (N*K);
  //cout << a << " " << b << " " << temp << endl;
  return (N*K) / gcd(N*K, temp);
}

int main() {

  cin >> N >> K >> A >> B;

  ll x = N*K, y = 0;

  ll a1 = A;
  ll a2 = (K - A) % K;
  for (ll i = 0; i < N; i++) {
    ll b1 = K*i + B;
    ll b2 = K*i + (K - B) % K;

    ll p = dist(a1,b1);
    ll q = dist(a1,b2);
    ll r = dist(a2,b1);
    ll s = dist(a2,b2);

    x = min(x, min(p, min(q, min(r, s))));
    y = max(y, max(p, max(q, max(r, s))));
  }

  cout << x << " " << y << endl;

  return 0;
}
