#include <iostream>
using namespace std;

#define ll long long
#define N 10

ll fact[N+1];

inline int bitcount(int n) {
  int x = 0;
  while (n) {
    x++;
    n &= n-1;
  }
  return x;
}

int main() {

  const int MAX = 1<<(2*N);

  fact[0] = 1;
  for (int i = 1; i <= N; i++) fact[i] = i*fact[i-1];

  ll ans = 0;
  for (int i = 0; i < MAX; i++) {
    if (bitcount(i) != N) continue;
    int a = -N*(N-1)/2;
    for (int j = 0; j < 2*N; j++) {
      if (i & (1 << j)) a+=j;
    }
    if (a % 11 == 0) {
      int z = (i & 1) + ((i>>1) & 1);
      ans += N-z;
    }
  }
  cout << ans*((fact[N-1]*fact[N])>>N) << endl;

  return 0;
}
