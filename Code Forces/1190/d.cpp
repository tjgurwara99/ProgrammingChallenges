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

vector<int> xs;
int xCount[MAXN];
map<int, int> xIndex;

#define LSB(x) ((x)&(-(x)))

void add(int x) {
  int i = xIndex[x];
  for (i < MAXN; i += LSB(i)) xCount[i]++;
}

int get(int i) {
  int total = 0;
  for (; i; i -= LSB(i)) total += xCount[i];
  return total;
}

int getRange(int x1, int x2) {
  int i = xIndex[x1], j = xIndex[x2];
  return get(j)-get(i-1);
}

int main() {

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> P[i].second >> P[i].first;
    xs.push_back(P[i].second);
  }

  sort(xs.begin(), xs.end());

  int distintX = 1;
  for (int i = 1; i < N; i++) {
    if (xs[i] != xs[distinctX-1]) xs[distinctX++] = xs[i];
  }
  for (int i = 0; i < distinctX; i++) xIndex[xs[i]] = i+1;

  sort(P, P+N);

  ll ans = 0;
  for (int i = N-1; i >= 0;) {
    int j = i;
    for (;j >= 0 && P[j].first == P[i].first; j--) {
      add(P[j].second);
      if (j < i) {

      }
    }

    ll n = (ll)xs.size();
    ans += n*(n+1)/2;
    i = j;
  }

  cout << ans << endl;

  return 0;
}
