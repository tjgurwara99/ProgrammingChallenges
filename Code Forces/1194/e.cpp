#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define SIZE(v) ((int)(v).size())
#define LINE tuple<int,int,int>
#define CMP(i) [](const LINE& a, const LINE& b) { return get<i>(a) < get<i>(b); }

#define LSB(x) ((x)&(-(x)))

int N;
vector<LINE> H, V;

inline bool inRange(int l, int u, int x) { return l <= x && x <= u; }

int ftree[11000];

void reset() {
  for (int i = 0; i < 11000; i++) ftree[i] = 0;
}

void add(int x, int k) {
  x += 5001;
  for (; x < 11000; x += LSB(x)) ftree[x]+=k;
}

int get(int x) {
  x += 5001;
  int total = 0;
  for (; x; x -= LSB(x)) total += ftree[x];
  return total;
}

int getRange(int x1, int x2) {
  return get(x2) - get(x1-1);
}

int main() {

  //cin.tie(0);
  //ios_base::sync_with_stdio(false);

  cin >> N;
  REP(i,N) {
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2) {
      if (y1 > y2) swap(y1,y2);
      V.push_back(make_tuple(y1,y2,x1));
    } else if (y1 == y2) {
      if (x1 > x2) swap(x1,x2);
      H.push_back(make_tuple(x1,x2,y1));
    }
  }


  sort(H.begin(), H.end(), CMP(2));

  ll ans = 0;

  for (int i1 = 0; i1 < SIZE(H); i1++) {
    const auto& h1 = H[i1];

    reset();

    vector<LINE> vs;
    for (const auto& v1: V) {
      if (inRange(get<0>(v1), get<1>(v1), get<2>(h1)) && inRange(get<0>(h1), get<1>(h1), get<2>(v1))) {
        vs.push_back(v1);
        add(get<2>(v1), 1);
      }
    }

    sort(vs.begin(), vs.end(), CMP(1));
    auto idx = vs.begin();

    for (int i2 = i1+1; i2 < SIZE(H); i2++) {
      const auto& h2 = H[i2];
      while (idx != vs.end() && get<1>(*idx) < get<2>(h2)) {
        add(get<2>(*idx), -1);
        idx++;
      }

      ll n = getRange(get<0>(h2), get<1>(h2));
      ans += n*(n-1)/2;
      //cout << i1 << " " << i2 << " " << n << endl;
    }
  }

  cout << ans << endl;

  return 0;
}
