#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int N, A[200000];

int main() {

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  int total = 0;

  cout << N+1 << endl;

  for (int i = N-1; i >= 0; i--) {
    int k = (N + ((i - (A[i] + total)) % N)) % N;  
    cout << "1 " << (i+1) << " " << k << endl;
    total = (total + k) % N;
  }

  cout << "2 " << N << " " << N << endl;

  return 0;
}
