/* Not working yet */
#include <cstdio>
#include <vector>
using namespace std;

#define MAX 10000000
#define ll unsigned long long

vector<ll> primes;
bool isComposite[MAX];

int digitSum(ll n) {
    int s = 0;
    for (; n; n /= 10) s += n % 10;
    return s;
}

inline bool isRTHarshad(ll n) {
    n /= 10;
    if (n == 0) return false;

    int s = digitSum(n);
    if (n % s != 0 || isComposite[n / s]) return false;

    for (; n; n /= 10) {
        if (n % s != 0) return false;
        s -= n % 10;
    }
    return true;
}

void genPrimes() {
    isComposite[0] = isComposite[1] = true;
    for (ll i = 0; i < MAX; i++) {
        if (isComposite[i]) continue;
        primes.push_back(i);
        for (ll j = i+i; j < MAX; j += i) isComposite[j] = true;
    }
}

bool isHarshad(ll n) {
    return n % digitSum(n) == 0;
}

int main() {

    genPrimes();

    ll sum = 0;

    for (ll p: primes) {
        if (isRTHarshad(p)) sum += p;
    }
    printf("%lld\n", sum);

    int count = 0;

    for (int i = 10000000; i < 100000000; i++) {
        if (isHarshad(i)) count++;
    }
    printf("%d\n", count);

    return 0;
}
