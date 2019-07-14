#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int T;
ll N, X;

int main() {

  cin >> T;
  while (T--) {
    cin >> N >> X;
    cout << 2*X << endl;
  }

  return 0;
}
