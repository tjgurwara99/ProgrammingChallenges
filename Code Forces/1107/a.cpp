#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int Q, N;
string A;

int main() {
  cin >> Q;
  while (Q--) {
    cin >> N;
    cin >> A;
    if (N == 2 && A[0]>=A[1]) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n2\n" << A[0] << " ";
    for (int i = 1; i < N; i++) cout << A[i];
    cout << "\n";
  }

  return 0;
}
