#include <cstdio>
#include <vector>
using namespace std;

#define ll long long

const int N = 10000000;

bool isComposite[N];
vector<ll> primes;

int main() {
    
    for (ll i = 2; i < N/2; i++) {
        if (isComposite[i]) continue;
        primes.push_back(i);
        for (ll j = i*i; j < N/2; j += i) isComposite[j] = true;
    }
    
    ll total = 0;
    for (int i = 0; i < (int)primes.size(); i++) {
        if (primes[i]*primes[i] >= N) break;
        for (int j = i+1; j < (int)primes.size(); j++) {
            if (primes[i]*primes[j] >= N) break;
        
            ll ans = 0;
            for (ll p = primes[i]; p <= N; p *= primes[i]) {
                ll q = p * primes[j];
                if (q > N) break;
                while (q * primes[j] <= N) q *= primes[j];
                if (q > ans) ans = q;
            }
            total += ans;
        }
    }
    
    printf("%lld\n", total);
    
    return 0;
}