#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXM 200000

ll N, M, K;
ll P[MAXM];

inline bool samePage(ll a, ll b) { return b < (a/K+1)*K; }

int main() {

  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 0; i < M; i++) {
    cin >> P[i];
    P[i]--;
  }

  int ans = 0;
  for (int i = 0; i < M; ans++) {
    int j = i;
    while (j < M && samePage(P[i]-i, P[j]-i)) j++;
    i = j;
  }

  cout << ans << endl;

  return 0;
}
