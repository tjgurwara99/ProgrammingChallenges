#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXN 200000

int N;
ll A[MAXN];

inline bool firstWins() {

  if (N == 1) {
    return A[0] % 2 == 1;
  }

  int sameIdx = -1;
  for (int i = 0; i < N-1; i++) {
    if (A[i] == A[i+1]) {
      if (sameIdx >= 0) return false;
      sameIdx = i;
    }
  }
  if (sameIdx >= 0) {
    if (A[sameIdx] == 0) return false;
    A[sameIdx]--;
    if (sameIdx > 0 && A[sameIdx-1] == A[sameIdx]) return false;
    return !firstWins();
  }

  ll moves = 0;
  for (int i = 0; i < N; i++) moves += A[i]-i;
  return moves % 2 == 1;
}

int main() {

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A,A+N);
  cout << (firstWins() ? "sjfnb\n" : "cslnb\n");

  return 0;
}
