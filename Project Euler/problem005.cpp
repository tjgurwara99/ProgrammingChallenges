#include <iostream>
using namespace std;

#define N 20

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  long long ans = 0;
  for (int i = 1; i <= N; i++) ans *= i / gcd(i, ans);
  cout << ans << endl;
  return 0;
}
