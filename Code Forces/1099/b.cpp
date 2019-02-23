#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int main() {

  int N;
  cin >> N;

  int x = 1;
  while (x*x <= N) x++;
  x--;

  int k = N-x*x;
  cout << x+x+(k ? (k > x ? 2 : 1) : 0) << endl;
  return 0;
}
