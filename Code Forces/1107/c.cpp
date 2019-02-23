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

int N, K;
ll A[MAXN];
string S;

int main() {

  cin >> N >> K;

  for (int i = 0; i < N; i++) cin >> A[i];
  cin >> S;

  ll total = 0;
  for (int i = 0; i < N; i++) {
    int j = i;
    while (j < N && S[j]==S[i]) j++;
    if (j-i > K) {
      sort(A+i,A+j);
      for (int k = j-K; k < j; k++) total += A[k];
    } else {
      for (int k = i; k < j; k++) total += A[k];
    }
    i = j-1;
  }

  cout << total << endl;

  return 0;
}
