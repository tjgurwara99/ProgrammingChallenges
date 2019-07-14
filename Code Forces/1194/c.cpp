#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define SIZE(s) ((int)(s).size())
#define ll long long

string S, T, P;

inline bool possible() {
  int s = 0;
  for (int t = 0; t < SIZE(T); t++) {
    if (s < SIZE(S) && S[s] == T[t]) {
      s++;
      continue;
    }
    auto idx = P.find(T[t]);
    if (idx == string::npos) return false;
    P.erase(idx, 1);
  }
  return s == SIZE(S);
}

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int Q;
  cin >> Q;
  while (Q--) {
    cin >> S >> T >> P;
    cout << (possible() ? "YES\n" : "NO\n");
  }

  return 0;
}
