#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    
    ll N, K, M, D, ans = 0;
    cin >> N >> K >> M >> D;
    for (ll d = 1; d <= D; d++) {
        if (K * (d-1) + 1 > N) break;
        ll xmin = N / (K * d);
        ll xmax = N / (K*(d-1) + 1);
        
        ll x = min(xmax, M);
        if (x >= xmin && d*x > ans) ans = d*x;
    }
    cout << ans << endl;
    
    return 0;
}