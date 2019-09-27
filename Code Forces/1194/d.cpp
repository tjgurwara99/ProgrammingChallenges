#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

ll N, K;

bool firstWins() {
  if (K % 3 != 0) return N % 3 != 0;
  N %= K+1;
  if (N == K) return true;
  return N % 3 != 0;
}

int main() {

  int T;
  cin >> T;

  while (T--) {
    cin >> N >> K;
    cout << (firstWins() ? "Alice\n" : "Bob\n");
  }

  return 0;
}
