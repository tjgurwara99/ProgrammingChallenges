#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, A[200];

int main() {

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  int ans = 100000000;
  for (int x = 1; x <= N; x++) {
    int t = 0;
    for (int i = 1; i <= N; i++) {
      t += A[i]*2*(abs(x-i)+i-1+x-1);
    }
    ans = min(ans,t);
  }
  cout << ans << endl;

  return 0;
}
