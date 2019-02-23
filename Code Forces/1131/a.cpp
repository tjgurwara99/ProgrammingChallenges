#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int main() {

  ll w1, h1, w2, h2;
  cin >> w1 >> h1 >> w2 >> h2;

  if (w1 == w2) {
    cout << 2*(w1+h1+h2)+4 << endl;
  } else {
    cout << (2+h1+h2+w1+1+h1+1+w1-w2+h2+w2) << endl;
  }

  return 0;
}
