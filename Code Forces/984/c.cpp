#include <cstdio>
#define ll long long

inline ll gcd(ll a, ll b) {
    ll c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    
    int T;
    scanf("%d", &T);
    
    while (T--) {
        ll p, q, b;
        scanf("%lld %lld %lld", &p, &q, &b);
        
        q /= gcd(q, p);
        
        ll g = gcd(q, b);
        while (g != 1) {
            while (!(q % g)) q /= g;
            g = gcd(q, b);
        }
        
        printf((q == 1) ? "Finite\n" : "Infinite\n");
    }
    
    return 0;
}