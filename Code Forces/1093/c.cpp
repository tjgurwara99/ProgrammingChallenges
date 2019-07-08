#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long 
#define MAXN 300000

int N; 
ll A[MAXN], B[MAXN];

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N/2; i++) {
    cin >> B[i];

    if (i) {
      A[i] = A[i-1];
      A[N-i-1] = B[i]-A[i];

      if (A[N-i-1] > A[N-i]) {
        A[N-i-1] = A[N-i];
        A[i] = B[i]-A[N-i-1];
      }
    } else {
      A[0] = 0;
      A[N-1] = B[0];
    }
  }
  
  for (int i = 0; i < N; i++) cout << A[i] << "\n";

  return 0;
}

