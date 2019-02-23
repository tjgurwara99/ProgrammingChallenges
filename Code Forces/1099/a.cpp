#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int W, H, U1, D1, U2, D2;

int main() {

  cin >> W >> H >> U1 >> D1 >> U2 >> D2;

  for (int i = H; i > 0; --i) {
    W+=i;
    if (i == D1) W=max(W-U1,0);
    if (i == D2) W=max(W-U2,0);
  }
  cout << W << endl;

  return 0;
}
