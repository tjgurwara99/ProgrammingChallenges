#include <iostream>
#include <vector>
using namespace std;

// Useful result:
// An even deck of size n is returned after k perfect riffle shuffles
// where k is the smallest no. where n-1 divides 2^k-1.

#define ll long long
#define N 60

vector<pair<ll,int>> primeFactorise(ll n) {
  vector<pair<ll,int>> pfs;
  ll p = 2;
  while (p*p <= n) {
    int i = 0;
    while (n % p == 0) {
      n /= p;
      i++;
    }
    if (i) pfs.push_back(make_pair(p, i));
    p += 1;
  }
  if (n > 1) pfs.push_back(make_pair(n,1));
  return pfs;
}

void genFact(vector<ll>& facts, vector<pair<ll,int>>& pfs, int idx, ll acc) {
  if (idx == pfs.size()) {
    facts.push_back(acc);
    return;
  }
  for (int i = 0; i <= pfs[idx].second; i++) {
    genFact(facts, pfs, idx + 1, acc);
    acc *= pfs[idx].first;
  }
}

vector<ll> getFactors(ll n) {
  vector<pair<ll,int>> pfs = primeFactorise(n);
  vector<ll> facts;
  genFact(facts, pfs, 0, 1);
  return facts;
}

int main() {

  ll factor = (1LL<<N)-1;
  vector<ll> A = getFactors(factor), B = getFactors(N);

  ll ans = 0;
  for (auto f : A) {
    bool hasN = true;
    for (auto g: B) {
      if (g != N && ((1LL<<g)-1) % f == 0) {
        hasN = false;
        break;
      }
    }
    if (hasN) ans += f+1;
  }

  cout << ans << endl;

  return 0;
}
