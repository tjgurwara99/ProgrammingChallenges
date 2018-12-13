#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

ll N, S, V[2000];

int main() {

  cin >> N >> S;

  ll total = 0;
  for (int i = 0; i < N; i++) {
    cin >> V[i];
    total += V[i];
  }

  if (total < S) {
    cout << "-1\n";
    return 0;
  }

  sort(V, V+N);

  for (int i = N-1; i > 0 && S > 0; i--) {
    ll d = min(V[i] - V[0], S);
    V[i] -= d;
    S -= d;
  }

  cout << V[0] - (S/N + min(S % N, 1LL)) << endl;

  return 0;
}
