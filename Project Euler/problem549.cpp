// Correct solution
// in about 10s 
#include <cstdio>
#include <vector>
using namespace std;

#define ll long long
#define MAX 100000001

vector<int> primes;
bool isComposite[MAX+1];
int DP[MAX+1];

inline int s(int n) {

    if (!isComposite[n]) return DP[n] = n;

    int maxPowNum = 0;
    int orig = n;

    int p;
    for (int i = 0; i < (int)primes.size(); i++) {
        if (n % primes[i] == 0) {
            p = primes[i];
            break;
        } 
    }

    int currentPow = 0;
    for (; n % p == 0; currentPow++) n /= p;

    int k = 0;
    while (currentPow > 0) {
        k += p;
        for (int tK = k; tK && tK % p == 0; tK /= p) currentPow--;
    }

    return DP[orig] = k > DP[n] ? k : DP[n];
}

int main() {

    // Prime sieve
    isComposite[0] = isComposite[1] = true;
    for (int i = 0; i < MAX; i++) {
        if (isComposite[i]) continue;
        primes.push_back(i);
        for (int j = i+i; j < MAX; j += i) isComposite[j] = true;
    }

    // Add all s(i) 
    ll total = 0;
    for (int i = 2; i < MAX; i++) total += s(i);
    printf("%lld\n", total);

    return 0;
}
