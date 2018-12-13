#include <iostream>
#include <cassert>
using namespace std;

#define ll long long
#define MOD 1000000007LL

ll N;
string S;

int main() {

  cin >> S;
  N = (int)S.size();

  int curr = 0;
  ll ans = 1;

  for (int i = 0; i < N; i++) {
    if (S[i] == 'a') {
      curr++;
    } else if (S[i] == 'b') {
      ans = (ans * (1 + curr)) % MOD;
      curr = 0;
    }
  }
  ans = (ans * (1+curr)) % MOD;

  cout << ans-1 << endl;

  return 0;
}
