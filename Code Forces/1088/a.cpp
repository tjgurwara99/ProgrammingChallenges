#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

  int x;
  cin >> x;

  bool found = false;
  
  for (int b = 1; b <= x && !found; b++) {
    for (int a = b; a <= x && !found; a += b) {
      if (a*b > x && a/b < x) {
        cout << a << " " << b << endl;
        found = true;
      }
    }
  }

  if (!found) {
    cout << -1 << endl;
  }

  return 0;
}
