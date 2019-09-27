#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int N, M;
string S[60000];

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;

  while (T--) {
    cin >> N >> M;
    REP(i,N) cin >> S[i];

    int maxRow = 0;
    int maxCol = 0;
    int intersect = 0;
    vector<int> maxRows;
    REP(r,N) {
      int cnt = 0;
      for (const char& c: S[r]) if (c == '*') cnt++;
      maxRow = max(maxRow, cnt);
    }
    REP(r,N) {
      int cnt = 0;
      for (const char& c: S[r]) if (c == '*') cnt++;
      if (cnt == maxRow) maxRows.push_back(r);
    }
    FOR(i,0,M-1) {
      int cnt = 0;
      REP(r,N) if (S[r][i] == '*') cnt++;
      maxCol = max(maxCol, cnt);
    }
    FOR(i,0,M-1) {
      int cnt = 0;
      REP(r,N) if (S[r][i] == '*') cnt++;
      if (cnt == maxCol) {
        for (const int& r: maxRows) {
          if (S[r][i] == '.') intersect=1;
        }
      }
    }
    cout << M+N-intersect-maxCol-maxRow << "\n";
  }

  return 0;
}
