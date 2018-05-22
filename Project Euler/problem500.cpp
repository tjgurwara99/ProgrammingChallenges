#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define TARGET 500500
#define MOD 500500507
#define MAX_PRIME 8000000

struct prime_power {
    int p, power;
    prime_power(int p, int power) : p(p), power(power) {} 
    
    const bool operator<(const prime_power& other) const {
        return (log(log(p))-log(log(other.p))) > (log(2) * (other.power-power));
    }
};

inline ll modPow(ll base, ll p) {
    ll res = 1, acc = base;
    for (; p; p >>= 1) {
        if (p & 1) res = (res * acc) % MOD;
        acc = (acc * acc) % MOD;
    }
    return res;
}

bool isComposite[MAX_PRIME];
ll pow2[50];

priority_queue<prime_power> pq;

int main() {
    
    pq.push(prime_power(2, 1));
    for (int i = 3; i < MAX_PRIME; i+=2) {
        if (isComposite[i]) continue;
        pq.push(prime_power(i, 1));
        if (MAX_PRIME/i < i) continue;
        for (int j = i*i; j < MAX_PRIME; j += i) isComposite[j] = true;
    }
    
    ll res = 1;
    prime_power biggest_pow(8000000, 1);
    
    pow2[0] = 1;
    for (int i = 1; i < 50; i++) pow2[i] = (pow2[i-1] << 1) % MOD;
    
    for (int i = 0; i < TARGET; i++) {
        prime_power next = pq.top();
        pq.pop();
        res = (res * modPow(next.p, pow2[next.power-1])) % MOD;
        
        next.power++;
        if (biggest_pow < next) pq.push(next);
    }
    printf("%lld\n", res);
    
    return 0;
}