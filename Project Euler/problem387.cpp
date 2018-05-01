#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX_PRIME 10000000
#define MAX_HARSHAD ((long long)1e13)
#define ll long long

vector<ll> primes;
bool isComposite[MAX_PRIME];

inline int digitSum(ll n) {
    int s = 0;
    for (; n; n /= 10) s += n % 10;
    return s;
}

inline bool isPrime(ll n) {
    if (n < MAX_PRIME) return !isComposite[n];
    for (int p = 0; primes[p]*primes[p] <= n; p++) {
        if (n % primes[p] == 0) return false;
    }
    return true;
}

int main() {

    isComposite[0] = isComposite[1] = true;
    for (ll i = 0; i < MAX_PRIME; i++) {
        if (isComposite[i]) continue;
        primes.push_back(i);
        for (ll j = i*i; j < MAX_PRIME; j += i) isComposite[j] = true;
    }
    
    queue<ll> hs;
    for (int i = 1; i < 10; i++) hs.push(i);
    
    ll ans = 0;
    
    while (!hs.empty()) {
        ll h = hs.front();
        hs.pop();
        int s = digitSum(h);
        bool strong = isPrime(h/s);
        
        for (int i = 0; i < 10; i++) {
            ll h2 = h*10+i;
            if (strong && isPrime(h2)) ans += h2;
            
            if (h2 >= MAX_HARSHAD) continue;
            if (h2 % (s + i)) continue;
            hs.push(h2);
        }
    }
    
    printf("%lld\n", ans);

    return 0;
}
