#include <iostream>
using namespace std;

#define N 100

int DP[N][4];

inline void addValue(int p) {
  for (int i = p; i < N; i++) {
    DP[i][2] += DP[i-p][1];
    DP[i][3] += DP[i-p][2];
  }
}

int main() {
  for (int k = 1; k <= 20; k++) DP[2*k][1] = 1;
  DP[50][1] = 1;

  for (int p = 1; p <= 20; p++) {
    addValue(p);
    addValue(p*2);
    addValue(p*3);
  }
  addValue(25);
  addValue(50);

  int ans = 0;
  for (int i = 1; i < N; i++) {
    for (int d = 1; d <= 3; d++) ans += DP[i][d];
  }
  cout << ans << endl;

  return 0;
}
