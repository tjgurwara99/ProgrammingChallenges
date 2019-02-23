#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXN 200000

ll N, K, M, A[MAXN];

int main() {

  cin >> N >> K >> M;
  ll total = 0;
  FOR(i,0,N-1) {
    cin>>A[i];
    total += A[i];
  }

  sort(A, A+N);
  double ans = 0;
  for (int numRemoved = 0; numRemoved <= M && numRemoved < N; numRemoved++) {
    ll subTotal = total + min(M-numRemoved, K*(N-numRemoved));
    ans = max(ans, (subTotal * 1.0) / (N - numRemoved));
    total -= A[numRemoved];
  }
  
  printf("%.10lf\n", ans);

  return 0;
}
