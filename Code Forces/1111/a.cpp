#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

bool isVowel(char c) {
  return c=='a' || c=='e' || c=='i' || c == 'o' || c == 'u';
}

int main() {

  string S, T;
  cin >> S >> T;

  bool valid = S.size() == T.size();
  for (int i = 0; i < (int)min(S.size(), T.size()); i++) {
    if (isVowel(S[i]) != isVowel(T[i])) valid = false;
  }

  cout << (valid ? "Yes\n" : "No\n");

  return 0;
}
