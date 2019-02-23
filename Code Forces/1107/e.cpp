/* Incorrect attempt :( */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int N, K;
string S;
ll A[200], B[200];
vector<int> C;

ll DP[1000];

int main() {

  cin >> N >> S;
  REP(i,N) cin >> A[i];
  REP(i,N) {
    FOR(j,1,i) B[i]=max(B[i],A[j]+B[i-j]);
  }

  int curr = 1;
  FOR(i,1,N-1) {
    if (S[i] != S[i-1]) {
      C.push_back(curr);
      curr = 0;
    }
    curr++;
  }
  C.push_back(curr);
  K = (int)C.size();

  for (int i = K-1; i >= 0; i--) {
    DP[i] = B[C[i]] + DP[i+1];
    int tot = C[i];
    int val = 0;
    for (int j = i+1; j < K; j++) {
      if ((j-i)%2 == 0) {
        tot += C[j];
      } else {
        val += B[C[j]];
      }
      DP[i] = max(DP[i], val+B[tot]+DP[j+1]);
    }
    tot = C[i];
    val = 0;
    for (int j = i+1; j < K; j++) {
      if ((j-i)%2 == 1) {
        tot += C[j];
      } else {
        val += B[C[j]];
      }
      DP[i] = max(DP[i], val+B[tot]+DP[j+1]);
    }
  }

  cout << DP[0] << endl;

  return 0;
}
