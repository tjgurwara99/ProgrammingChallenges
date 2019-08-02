#include <iostream>
#include <cmath>
using namespace std;

#define N 64000000
#define ll long long

ll sigma[N+1];

inline bool isSquare(ll x) {
  ll y = (int)sqrt(x);
  return y*y==x;
}

int main() {

  for (int d = 1; d <= N; d++) {
    ll d2 = ((ll)d)*d;
    for (int i = d; i <= N; i+=d) sigma[i]+=d2;
  }
  ll total = 0;
  for (int i = 1; i <= N; i++) {
    if (isSquare(sigma[i])) total += i;
  }
  cout << total << endl;
  return 0;
}
