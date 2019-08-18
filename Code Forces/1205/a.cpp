#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXN 200000

int N;
int A[MAXN];

int main() {

  cin >> N;
  
  if (N % 2 == 0) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < N; i++) {
      if (i % 2 == 0) {
        A[i] = 2*i+1;
        A[N+i] = 2*i+2;
      } else {
        A[i] = 2*i+2;
        A[N+i] = 2*i+1;
      }
    }
    for (int i = 0; i < 2*N-1; i++) cout << A[i] << " ";
    cout << A[2*N-1] << endl;
  }

  return 0;
}
