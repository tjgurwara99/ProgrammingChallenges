#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int main() {
  ll N;
  cin >> N;
  ll x, y;
  x = y = 0;
  ll ans = 1;
  while (N--) {
    ll a, b;
    cin >> a >> b;
    if (min(a,b) >= max(x,y)) {
      ans += min(a,b)-max(x,y)+1;
      if (x==y) ans--;
    }
    x = a; y = b;
  }
  cout << ans << endl;

  return 0;
}
