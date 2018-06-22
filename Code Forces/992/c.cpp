#include <iostream>
using namespace std;

#define ll long long
#define MOD ((long long)(1e9+7))

ll X, K;

ll fastExp(ll p, ll q) {
    if (q == 0) return 1;
    ll a = fastExp(p, q/2);
    a = (a*a) % MOD;
    if (q % 2) a = (a*p) % MOD;
    return a;
}

int main() {
    
    cin >> X >> K;
    
    if (X == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    X %= MOD;
    ll p2 = fastExp(2, K);
    
    ll ans = (2*p2*X - p2 + 1) % MOD;
    if (ans < 0) ans += MOD;
    
    cout << ans << endl;
    
    return 0;
}