#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

ll N, K;
string S, T;

int main() {

  cin >> N >> K >> S >> T;

  if (K == 1) {
    cout << N << endl;
    return 0;
  }

  int s = 0;
  while (s < N && S[s] == T[s]) s++;

  ll ans = N+(N-s);
  ll curr = 0;
  K -= 2;

  for (int i = s+1; i < N && K > 0; i++) {
    int chg = 0;
    if (S[i] == 'a') chg++;
    if (T[i] == 'b') chg++;

    ll d = min(K, curr+chg);
    ans += d * (N-i);
    K -= d;
    curr += d;
  }

  cout << ans << endl;

  return 0;
}
