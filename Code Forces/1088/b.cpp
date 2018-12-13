#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

ll N, K, A[200000], B[200000];

int main() {

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    B[i] = A[i];
  }

  sort(B, B+N);

  ll left = K, i = 0;
  ll tot = 0;

  while (left && i < N) {
    if (B[i] > tot) {
      cout << B[i]-tot << "\n";
      tot = B[i];
      left--;
    }
    i++;
  }

  while (left) {
    cout << "0\n";
    left--;
  }

  return 0;
}
