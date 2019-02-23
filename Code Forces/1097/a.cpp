#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int main() {

  string S;
  cin >> S;

  for (int i = 0; i < 5; i++) {
    string T;
    cin >> T;

    if (T[0]==S[0]||T[1]==S[1]) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}
