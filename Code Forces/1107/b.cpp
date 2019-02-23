#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int main() {
  ll n;
  cin >> n;
  while (n--) {
    ll k, x;
    cin >> k >> x;
    cout << (x + (k-1)*9) << "\n";
  }

  return 0;
}
