#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int N, A[16];

int main() {

  cin >> N;
  REP(i,N) cin>>A[i-1];

  FOR (i,0,(1<<N)-1) {
    int t = 0;
    FOR(j,0,N-1) {
      if (i & (1<<j)) t+=A[j];
      else t-=A[j];
    }
    t = (360 + (t % 360)) % 360;
    if (t==0) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}
