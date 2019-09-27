#include <iostream>
#include <vector>
using namespace std;

#define MAX 50000
#define MOD 1000000000
#define ll long long

bool isComposite[MAX];
vector<int> primes;
ll S[MAX];

int main() {
  isComposite[0] = isComposite[1] = true;
  for (ll i = 2; i < MAX; i++) {
    if (isComposite[i]) continue;
    primes.push_back(i);
    for (ll j = i*i; j < MAX; j+=i) isComposite[j] = true;
  }

  S[0] = 1;
  for (int p: primes) {
    for (int i = p; i < MAX; i++) {
      S[i] += (S[i-p]*p) % MOD;
      S[i] %= MOD;
    }
  }

  int a = 1, b = 1;
  ll total = 0;
  for (int i = 2; i <= 24; i++) {
    total += S[b];
    int c = a + b;
    a = b;
    b = c;
  }
  cout << (total % MOD) << endl;

  return 0;
}
