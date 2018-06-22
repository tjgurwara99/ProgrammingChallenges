#include <iostream>
using namespace std;

#define ll long long

ll l, r, x, y;

inline ll gcd(ll a, ll b) {
    ll c = 0;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    
    cin >> l >> r >> x >> y;
    
    ll prod = x*y;
    int ans = 0;
    
    ll start = max(l, prod / r);
    start += (x - (start % x)) % x;
    
    for (ll i = start; i*i <= prod && i <= r; i += x) {
        if (prod % i != 0) continue;
        
        ll j = prod / i;
        if (j < l || j > r) continue;
        
        if (gcd(i, j) == x) {
            if (i == j) {
                ans++;
            } else {
                ans += 2; 
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}