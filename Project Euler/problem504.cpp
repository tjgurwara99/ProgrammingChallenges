#include <iostream>
using namespace std;

#define M 100

int DP[M+1][M+1];
bool isSquare[4*M*M+1];

inline int gcd(int a, int b) {
  int c;
  while (b) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

// Lattice points strictly within right triangle widthxheight at origin
inline int triangleLatticePoints(int width, int height) {
  return ((width+1)*(height+1)-width*2-height*2-gcd(width,height)+1)/2;
}

int main() {

  for (int w = 1; w <= M; w++) {
    for (int h = w; h <= M; h++) {
      DP[w][h] = DP[h][w] = triangleLatticePoints(w, h);
    }
  }

  for (int i = 0; i <= 2*M; i++) isSquare[i*i] = true;

  int ans = 0;

  for (int a = 1; a <= M; a++) {
    for (int b = 1; b <= M; b++) {
      for (int c = 1; c <= M; c++) {
        for (int d = 1; d <= M; d++) {
          int points = DP[a][b] + DP[b][c] + DP[c][d] + DP[d][a];
          points += a + b + c + d - 3; // points along axis (counted origin 4 times)
          if (isSquare[points]) ans++;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
