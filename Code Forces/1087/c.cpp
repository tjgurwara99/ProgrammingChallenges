#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline int dist(int x, int y, int p, int q) {
  return abs(x - p) + abs(y - q);
}

bool cleared[2000][2000];

void range(int a, int b, int c, int d) {
  if (a == c && b == d) return;
  int step = c > a ? 1 : -1;
  for (int x = a; x != c; x+=step) {
    cout << x << " " << b << "\n";
  }
  step = d > b ? 1 : -1;
  for (int y = b; y != d; y+=step) {
    cout << c << " " << y << "\n";
  }
}

int main() {

  int xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;

  int minX = -1, minY = -1, minDist = -1;

  for (int x = 0; x <= 1000; x++) {
    for (int y = 0; y <= 1000; y++) {
      int d = 1;
      d += dist(xa, ya, x, y);
      d += dist(xb, yb, x, y);
      d += dist(xc, yc, x, y);

      if (minDist == -1 || d < minDist) {
        minDist = d;
        minX = x;
        minY = y;
      }
    }
  }

  cout << minDist << "\n";
  cout << minX << " " << minY << "\n";
  range(xa, ya, minX, minY);
  range(xb, yb, minX, minY);
  range(xc, yc, minX, minY);

  return 0;
}
