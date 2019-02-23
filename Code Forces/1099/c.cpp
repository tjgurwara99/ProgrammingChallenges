#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

string S;
int N, K;

int main() {

  cin >> S >> K;
  N = (int)S.size();

  int minLength = 0, maxLength = 0;
  for (int i = 0; i < N; i++) {
    if (S[i]=='*' || S[i]=='?') minLength--;
    else minLength++;
    if (S[i] == '*') maxLength = 100000;
    else if (S[i] != '?') maxLength++;
  }

  if (minLength > K || maxLength < K) {
    cout << "Impossible\n";
    return 0;
  }

  int needed = K-minLength;
  string ans = "";
  for (int i = 0; i < N; i++) {
    if (S[i]=='?') continue;
    if (S[i]=='*') {
      if (needed) i--;
      else continue;
    }
    bool optional = i+1<N && (S[i+1]=='*' || S[i+1]=='?');
    if (optional && needed) {
      ans += S[i];
      needed--;
    } else if (!optional) {
      ans += S[i];
    }
  }
  cout << ans << endl;

  return 0;
}
