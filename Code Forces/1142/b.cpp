/**
Attempt at a solution, didn't work
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXN 205000

int N, M, Q;
int P[MAXN], P_inv[MAXN], A[MAXN], A_idx[MAXN];
int P_interval[MAXN][2]; // start,end
int maxChainLen[MAXN];
int maxChainPos[MAXN][2]; // furthest end point, furthest penultimate point (if applicable)
bool hasShift[MAXN];

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M >> Q;
  for (int i = 1; i <= N; i++) {
    cin >> P[i];
    P_inv[P[i]] = i;
  }
  for (int i = 1; i <= M; i++) {
    cin >> A[i];
    A_idx[i] = i;
  }

  sort(A_idx+1,A_idx+M+1, [&](int a, int b) {
    int p = P_inv[A[a]], q = P_inv[A[b]];
    if (p < q) return true;
    if (p > q) return false;
    return a < b;
  });

  for (int i = 1; i <= N; i++) {
    P_interval[i][0] = i==1 ? 1 : P_interval[i-1][1];
    P_interval[i][1] = P_interval[i][0];
    while (P_interval[i][1] <= M && A[A_idx[P_interval[i][1]]] == P[i]) {
      P_interval[i][1]++;
    }
  }

  for (int i = 2; i <= 2*N-1; i++) {
    int prevElem = i-1;
    int currElem = i;
    if (prevElem > N) prevElem -= N;
    if (currElem > N) currElem -= N;

    int prevPos = P_interval[prevElem][0];
    int maxPrevChainLen = 0;
    int maxPrevChainPos = -1;
    int sndPrevChainPos = -1;

    for (int j = P_interval[currElem][0]; j < P_interval[currElem][1]; j++) {
      while (A_idx[prevPos] < A_idx[j]) {
        if (maxChainLen[prevPos] > maxPrevChainLen) {
          if (maxPrevChainLen < N-1) {
            maxPrevChainLen = maxChainLen[prevPos];
          }
        }
        if (maxChainLen[prevPos] == maxPrevChainLen) {
          if (maxChainPos[prevPos][0] > maxPrevChainPos) {
            maxPrevChainPos = maxChainPos[prevPos][0];
          }
          if (maxChainPos[prevPos][1] > sndPrevChainPos) {
            sndPrevChainPos = maxChainPos[prevPos][1];
          }
        }
        prevPos++;
      }
      maxChainLen[j] = maxPrevChainLen + 1;
    }
  }

  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
  }

  for (int i = 1; i <= M; i++) {
    cout << A_idx[i] << " " << maxChainLen[i] << endl;
  }


  return 0;
}
