#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXN 1000000

int N;
int correct;
int positives[MAXN];
int negatives[MAXN];

int main() {

  cin >> N;
  REP(t,N) {
    string S;
    cin >> S;

    int minD = 0;
    int d = 0;
    for (int i = 0; i < (int)S.size(); i++) {
      if (S[i] == '(') {
        d++;
      } else {
        d--;
      }
      minD = min(d, minD);
    }

    if (d == 0 && minD == 0) {
      correct++;
    } else if (d > 0 && minD == 0) {
      positives[d]++;
    } else if (d < 0 && minD == d) {
      negatives[-d]++;
    }
  }

  int ans = correct/2;
  for (int i = 1; i < MAXN; i++) {
    ans += min(positives[i],negatives[i]);
  }

  cout << ans << endl;

  return 0;
}
