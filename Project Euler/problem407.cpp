#include <iostream>
#include <vector>
using namespace std;

#define N 10000000
#define ll long long

vector<int> primePowers;

void primeFactorise(int n) {
  primePowers.clear();
  int p = 2; int i = 0;
  while (!(n & 1)) {
    i++;
    n >>= 1;
  }
  if (i) primePowers.push_back(1 << i);

  p++;
  while (p*p <= n) {
    int i = 1;
    while (n % p == 0) {
      i *= p;
      n /= p;
    }
    if (i > 1) primePowers.push_back(i);
    p+=2;
  }
  if (n > 1) primePowers.push_back(n);
}

int modInv(int a, int b) {
  int b0 = b;
  int s = 1, t = 0;
  int u = 0, v = 1;
  while (b) {
    int q = a/b;
    int oldB = b;
    b = a - q*b;
    a = oldB;

    int oldS = s; ll oldT = t;
    s = u; t = v;
    u = oldS - q*u; v = oldT - q*v;
  }
  s %= b0;
  if (s < 0) s += b0;
  return s;
}

int main() {

  ll total = 0;
  for (int n = 2; n <= N; n++) {
    primeFactorise(n);
    vector<int> x;
    for (const auto& p: primePowers) {
      int M = n / p;
      int a = modInv(M, p);
      x.push_back(a*M);
    }
    int K = (int)x.size();
    int ans = 1;
    for (int i = 1; i < (1<<K); i++) {
      int s = 0;
      for (int j = 0; j < K; j++) if (i & (1 << j)) s += x[j];
      ans = max(s % n,ans);
    }
    total += ans;
  }
  cout << total << endl;

  return 0;
}
