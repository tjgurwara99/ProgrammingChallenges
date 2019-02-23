#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int N;
ll A[200], B[200];

int main() {

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  sort(A,A+N);
  
  int a = 0;
  int b = N-1;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) B[a++] = A[i];
    else B[b--] = A[i];
  }

  cout << B[0];
  for (int i = 1; i < N; i++) cout << " " << B[i];
  cout << endl;

  return 0;
}
