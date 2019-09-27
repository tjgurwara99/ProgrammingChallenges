#include <iostream>
using namespace std;

#define N 40

// Dynamic programming on digit idx, digit at index, mask of digits required in the number
long long DP[N][10][1 << 10];

int main() {
  long long ans = 0;
  for (int d = 0; d < 10; d++) {
    DP[0][d][1<<d] = DP[0][d][0] = 1;
  }
  for (int pos = 1; pos < N; pos++) {
    for (int d = 0; d < 10; d++) {
      for (int mask = 0; mask < (1<<10); mask++) {
        if (d < 9) DP[pos][d][mask] += DP[pos-1][d+1][mask & (~(1<<d))];
        if (d > 0) DP[pos][d][mask] += DP[pos-1][d-1][mask & (~(1<<d))];
      }
      if (d) ans += DP[pos][d][(1<<10)-1];
    }
  }
  cout << ans << endl;
  return 0;
}
