#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 300000

int N, M, A[MAXN], B[MAXN];

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];

  return 0;
}
