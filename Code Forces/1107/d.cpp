#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXN 5201

int N;
char lineInput[10000];
bool M[MAXN][MAXN];
int DP[MAXN][MAXN];

inline bool isCompressible(int x) {
  int k = N/x;
  for (int i = 0; i < k; i++) {
    int r = x*(i+1)-1;
    for (int j = 0; j < k; j++) {
      int c = x*(j+1)-1;
      if (DP[r][c] < x) return false;
    }
  }
  return true;
}

int main() {

  scanf("%d",&N);
  for (int i = 0; i < N; i++) {
    scanf(" %s", lineInput);
    for (int j = 0; j <(N>>2); j++) {
      int k = lineInput[j]-'0';
      if (lineInput[j]>='A') k = 10+(lineInput[j]-'A');
      M[i][4*j+0] = (k >> 3) & 1;
      M[i][4*j+1] = (k >> 2) & 1;
      M[i][4*j+2] = (k >> 1) & 1;
      M[i][4*j+3] = (k >> 0) & 1;
    }
  }

  for (int i = 0; i < N; i++) {
    DP[i][0] = DP[0][i] = 1;
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      DP[i][j] = 1;
      if (M[i-1][j-1] == M[i][j-1] && M[i-1][j] == M[i][j-1] && M[i][j] == M[i-1][j-1]) {
        DP[i][j] += min(DP[i-1][j-1], min(DP[i][j-1], DP[i-1][j]));
      }
    }
  }
  /*for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << (M[i][j] ? "1" : "0");
    }
    cout << endl;
  }*/

  int ans = 1;
  int fac = 2;
  int K = N;
  for (; fac*fac <= K; fac++) {
    if (K % fac) continue;
    K /= fac;
    if (isCompressible(ans * fac)) ans *= fac;
    fac--;
  }
  if (K > 1 && isCompressible(ans * K)) ans *= K;

  printf("%d\n", ans);

  return 0;
}
