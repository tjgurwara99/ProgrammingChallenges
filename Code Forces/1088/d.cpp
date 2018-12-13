#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline int query(int c, int d) {
  cout << "? " << c << " " << d << endl;
  int x;
  cin >> x;
  return x;
}

int main() {

  int pA = 0, pB = 0;
  int c = query(pA, pB);

  for (int i = 29; i >= 0; i--) {
    int b = 1 << i;
    if (c == 0) {
      int x = query(pA | b, pB);
      if (x < 0) {
        pA |= b;
        pB |= b;
      }
      continue;
    }

    int x = query(pA | b, pB);
    int y = query(pA, pB | b);

    // diff bits
    if (x == y) {
      if (c > 0) {
        pA |= b;
      } else {
        pB |= b;
      }
      c = x;
      continue;
    }

    // same bits
    if (x < 0) {
      pA |= b;
      pB |= b;
    }
  }

  cout << "! " << pA << " " << pB << endl;

  return 0;
}
