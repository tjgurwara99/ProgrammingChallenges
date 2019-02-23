#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXN 1005

int N, M;
int A[MAXN][MAXN];

int parent[MAXN*2];
int sz[MAXN*2];

vector<int> greaterThan[MAXN*2];
int edgeCount[MAXN*2];
int nodeLabel[MAXN*2];

int root(int p) { return p == parent[p] ? p : (parent[p] = root(parent[p])); }

void join(int a, int b) {
  int p = root(a), q = root(b);
  if (p == q) return;
  if (sz[p] < sz[q]) swap(p, q);
  sz[p] += sz[q];
  parent[q] = p;
}

bool solve() {
  vector<int> search;
  int edgesLeft = 0;

  for (int i = 1; i <= N+M; i++) {
    for (int j: greaterThan[i]) edgeCount[j]++;
  }

  for (int i = 1; i <= N+M; i++) {
    if (root(i)==i && edgeCount[i]==0) {
      search.push_back(i);
      nodeLabel[i] = 1;
    }
    edgesLeft += edgeCount[i];
  }

  while (search.size() > 0) {
    int a = search[search.size()-1];
    search.pop_back();
    for (int b: greaterThan[a]) {
      edgeCount[b]--;
      edgesLeft--;
      if (!edgeCount[b]) {
        search.push_back(b);
        nodeLabel[b] = nodeLabel[a]+1;
      }
    }
  }

  return edgesLeft==0;
}

int main() {

  cin >> N >> M;

  for (int i = 1; i <= N+M; i++) {
    parent[i] = i;
    sz[i] = 1;
  }

  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    for (int j = 0; j < M; j++) {
      if (S[j] == '=') join(i+1,N+j+1);
      if (S[j] == '<') A[i][j] = -1;
      if (S[j] == '>') A[i][j] = 1;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (A[i][j] == -1) greaterThan[root(i+1)].push_back(root(N+j+1));
      if (A[i][j] == 1) greaterThan[root(N+j+1)].push_back(root(i+1));
    }
  }

  if (solve()) {
    cout << "Yes\n";
    cout << nodeLabel[root(1)];
    for (int i = 2; i <= N; i++) {
      cout << " " << nodeLabel[root(i)];
    }
    cout << endl;
    cout << nodeLabel[root(N+1)];
    for (int i = 2; i <= M; i++) {
      cout << " " << nodeLabel[root(N+i)];
    }
    cout << endl;
  } else {
    cout << "No\n";
  }

  return 0;
}
