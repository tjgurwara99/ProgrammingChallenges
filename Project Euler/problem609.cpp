#include <iostream>
#include <vector>
using namespace std;

#define N 100000000
#define ll long long

bool isComposite[N+1];
int pi[N+1];
int C[N+1];

int main() {

  isComposite[0] = isComposite[1] = true;
  for (ll i = 2; i <= N; i++) {
    if (isComposite[i]) continue;
    for (ll j = i*i; j <= N; j += i) isComposite[j] = true;
  }
  for (int i = 2; i <= N; i++) pi[i] = isComposite[i] ? pi[i-1] : pi[i-1]+1;

  C[1] = 0;
  for (int i = 2; i <= N; i++) C[i] = isComposite[i] ? C[pi[i]] : C[pi[i]]+1;

  cout << C[10] << endl;
  cout << pi[N] << endl;

  return 0;
}
