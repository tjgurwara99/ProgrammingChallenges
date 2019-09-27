#include <iostream>
#include <algorithm>
using namespace std;

string S;
int N;

int main() {

  int T;
  cin >> T;

  while (T--) {
    cin >> S;
    N = (int)S.size();
    sort(S.begin(), S.end());

    if (S[0] == S[N-1]) {
      cout << -1 << endl;
    } else {
      cout << S << endl;
    }
  }
  
  return 0;
}
