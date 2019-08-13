#include <iostream>
using namespace std;

#define L 4

int DP[3][4];

int main() {
  for (int i = 0; i <= L; i++) {
    for (int l = 0; l < 3; l++) {
      for (int a = 0; a < 4; a++) {
        if (l == 2 || a == 3) {
          DP[l][a] = 0;
          continue;
        }
        if (i == 0) DP[l][a] = 1;
        else DP[l][a] = DP[l][0] + DP[l+1][0] + DP[l][a+1];
      }
    }
  }
  int ans = 0;
  for (int l = 0; l < 3; l++) for (int a = 0; a < 4; a++) ans += DP[l][a];
  cout << ans << endl;
  return 0;
}
