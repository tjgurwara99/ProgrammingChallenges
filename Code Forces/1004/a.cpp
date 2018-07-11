#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long

ll N, D, X[100];

inline ll minDist(ll pos) {
    ll d = (ll)2e9;
    for (int i = 0; i < N; i++) d = min(d, abs(pos - X[i]));
    return d;
}

int main() {

    scanf("%lld %lld", &N, &D);
    for (int i = 0; i < N; i++) scanf("%lld", &X[i]);

    set<ll> ps;
    for (int i = 0; i < N; i++) {
        if (minDist(X[i]+D) == D) ps.insert(X[i]+D);
        if (minDist(X[i]-D) == D) ps.insert(X[i]-D);
    }
    printf("%d\n", (int)ps.size());

    return 0;
}