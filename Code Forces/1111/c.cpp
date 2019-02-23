#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXK 200000

ll N, K, A, B, P[MAXK];

inline int countAvengers(ll start, ll end) {
  int a = (int)(lower_bound(P, P+K, start) - P);
  int b = (int)(lower_bound(P, P+K, end) - P);
  return b-a;
}

ll minPower(ll start, ll end) {
  ll mid = (start+end)/2;
  int cnt = countAvengers(start, end);
  if (cnt == 0) return A;
  ll ans = B*cnt*(end-start);
  if (end-start > 1) ans = min(ans, minPower(start,mid)+minPower(mid,end));
  return ans;
}

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> K >> A >> B;
  for (int i = 0; i < K; i++) {
    cin >> P[i];
    P[i]--;
  }
  sort(P, P+K);

  cout << minPower(0LL, 1LL<<N) << endl;

  return 0;
}
