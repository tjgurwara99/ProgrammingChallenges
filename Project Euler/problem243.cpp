#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

#define ll long long

const double RATIO = 15499.0/94744;

inline bool isPrime(int n) {
  int i = 2;
  while (i*i <= n) {
    if (n % i == 0) return false;
    i++;
  }
  return true;
}

int main() {

  vector<int> primes;
  double t = 1;
  ll n = 1;
  for (int i = 2;; i++) {
    if (!isPrime(i)) continue;
    primes.push_back(i);
    n *= i; t *= 1-1.0/i;
    if (t*n/(n-1) < RATIO) break;
  }

  int M = (int)primes.size();
  priority_queue<tuple<ll,double,int>> pq;
  for (int i = 0; i < M; i++) pq.push(make_tuple(-primes[i], 1-1.0/primes[i], i));

  bool found = false;
  while (!found) {
    auto next = pq.top();
    ll num = -get<0>(next);
    double tot = get<1>(next);
    pq.pop();

    for (int i = get<2>(next); i < M; i++) {
      int p = primes[i];
      double t = tot*(num % p == 0 ? 1 : 1-1.0/p);
      ll n = num * p;
      double r = t*n/(n-1);
      if (r < RATIO) {
        cout << n << endl;
        found = true;
        break;
      }
      pq.push(make_tuple(-n, t, i));
    }
  }

  return 0;
}
