#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int main() {

  int N, K;
  cin >> N >> K;

  for (int i = K-1; i >= 1; i--) {
    if (N % i == 0) {
      cout << (K*(N/i) + i) << endl;
      break;
    }
  }

  return 0;
}
