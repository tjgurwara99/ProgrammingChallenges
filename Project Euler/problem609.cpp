#include <iostream>
#include <vector>
using namespace std;

#define N 100000000
#define ll long long
#define MOD 1000000007

int isComposite[N+1];
vector<int> primes;
int pi[N+1];
int kCount[50];

int main() {

  isComposite[0] = isComposite[1] = 1;
  for (ll i = 2; i <= N; i++) {
    if (isComposite[i]) continue;
    primes.push_back(i);
    for (ll j = i*i; j <= N; j += i) isComposite[j] = 1;
  }

  for (int i = 2; i <= N; i++) pi[i] = pi[i-1]+1-isComposite[i];

  for (int i = 2; i <= N; i++) {
    for (int j = pi[i], k = isComposite[i]; j >= 1; j = pi[j]) {
      k += isComposite[j];
      kCount[k]++;
    }
  }

  ll ans = 1;
  for (int i = 0; i < 50; i++) if (kCount[i]) ans = (ans * kCount[i]) % MOD;
  cout << ans << endl;

  return 0;
}
