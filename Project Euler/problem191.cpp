#include <iostream>
using namespace std;

#define L 30
int DP[L+1][2][3];

int main() {
  // DP[l][i][j] is the number of prize sequences of length l
  // with at most i lates and at most j absences at the end
  DP[1][0][0] = 1;
  DP[1][0][1] = 2;
  DP[1][0][2] = 2;
  DP[1][1][0] = 2;
  DP[1][1][1] = 3;
  DP[1][1][2] = 3;
  for (int l = 2; l <= L; l++) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        DP[l][i][j] = DP[l-1][i][2];
        if (i) DP[l][i][j] += DP[l-1][i-1][2];
        if (j) DP[l][i][j] += DP[l-1][i][j-1];
      }
    }
  }
  cout << DP[L][1][2] << endl;
  return 0;
}
