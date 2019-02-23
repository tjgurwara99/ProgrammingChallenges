#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

string decrypt(string s) {
  int n = s.size();
  if (n == 1) return s;

  if (n % 2) {
    return decrypt(s.substr(1)) + s[0];
  } else {
    return decrypt(s.substr(0, n-1)) + s[n-1];
  }
}

int main() {

  string S;
  cin >> S;

  cout << decrypt(S) << endl;

  return 0;
}
