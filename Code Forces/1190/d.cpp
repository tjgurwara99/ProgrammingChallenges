#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXN 300000

int N;
pair<int,int> P[MAXN];

int main() {

  cin >> N;
  for (int i = 0; i < N; i++) cin >> P[i].second >> P[i].first;

  sort(P, P+N);

  set<int> xs;
  ll ans = 0;
  for (int i = N-1; i >= 0;) {
    int j = i;
    for (;j >= 0 && P[j].first == P[i].first; j--) {
      xs.insert(P[j].second);
    }
    ll n = (ll)xs.size();
    ans += n*(n+1)/2;
    i = j;
  }

  cout << ans << endl;

  return 0;
}
