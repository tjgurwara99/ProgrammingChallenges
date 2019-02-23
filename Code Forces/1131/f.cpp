#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXN 200000

int N;

int nextIdx[MAXN];
int parent[MAXN];
int leaf[MAXN];

int root(int p) {
  return p == parent[p] ? p : (parent[p] = root(parent[p]));
}

int main() {

  cin >> N;

  for (int i = 1; i <= N; i++) parent[i] = leaf[i] = i;

  for (int i = 0; i < N-1; i++) {
    int x, y;
    cin >> x >> y;
    int p = root(x);
    int q = root(y);
    nextIdx[leaf[p]] = q;
    parent[q] = p;
    leaf[p] = leaf[q];
  }

  int i = root(1);
  cout << i;
  i = nextIdx[i];
  while (i) {
    cout << " " << i;
    i = nextIdx[i];
  }
  cout << endl;

  return 0;
}
