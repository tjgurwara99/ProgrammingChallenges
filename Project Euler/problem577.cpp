#include <iostream>
using namespace std;

#define ll long long
#define N 12345

/*
 * Solution by considering the hexagon side lengths
 * and finding the smallest triangle for the first
 * occurrence. Then the number of such hexagons in
 * successive triangles follows triangle numbers
 * */

#define T(n) (((n)*1LL)*(n+1)/2)

int main() {

  ll ans = 0;
  for (int n = 3; n <= N; n++) {
    for (int i = 1; 3*i <= n; i++) {
      ans += i*T(n-3*i+1);
    }
  }
  // Closed form formula exists but this is already very fast
  cout << ans << endl;

  return 0;
}
