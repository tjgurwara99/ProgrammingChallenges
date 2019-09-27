#include <iostream>
using namespace std;

typedef long long ll;

const int N = 20000000, R = 15000000;
int primeFactor[N+1], pfSum[N+1];

int main() {
  for (int i = 1; i <= N; i++) primeFactor[i] = i;
  for (int i = 2; i*i <= N; i++) {
    if (primeFactor[i]<i) continue;
    for (int j = i*i; j <= N; j+=i) primeFactor[j] = i;
  }
  for (int i = 2; i <= N; i++) pfSum[i] = pfSum[i/primeFactor[i]]+primeFactor[i];

  ll ans = 0;
  for (int i = 1; i <= R; i++) ans += pfSum[N+1-i] - pfSum[i];
  cout << ans << endl;

  return 0;
}
