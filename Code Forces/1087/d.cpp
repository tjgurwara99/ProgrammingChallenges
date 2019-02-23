#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int E[1000000];
int main() {

  int N, S;
  cin >> N >> S;

  for (int i = 0; i < N-1; i++) {
    int a, b;
    cin >> a >> b;
    E[a]++;
    E[b]++;
  }

  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    if (E[i] == 1) cnt++;
  }

  cout << setprecision(10);
  cout << (S * 2.0) / cnt << endl;

  return 0;
}
