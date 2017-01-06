/* Correct answer in 182ms */
#include <cstdio>
#include <vector>
using namespace std;

#define ll long long
#define PMAX 100000
#define MAX 1000001

bool isComposite[PMAX];
vector<int> primes;

void genPrimes() {
    isComposite[0] = isComposite[1] = true;
    for (int i = 2; i < PMAX; i++) {
        if (isComposite[i]) continue;
        primes.push_back(i);
        for (int j = i+i; j < PMAX; j+=i) isComposite[j] = true;
    }
}

// First = firstPrime, Second = pointer to next set
pair<int, int> primeFact[MAX];
ll T[MAX];

inline void computeTotient(int n) {

    int p;
    for (p = 0; primes[p]*primes[p] <= n; p++) {
        if (n % primes[p] == 0) break;
    }

    // If n is prime
    if (primes[p]*primes[p] > n) {
        primeFact[n].first = n;
        primeFact[n].second = -1;
    }

    // Otherwise re-use prime factors as linked list
    else {

        int nextComp = n;
        for (; nextComp && nextComp % primes[p] == 0; nextComp /= primes[p] ) ;

        primeFact[n].first = primes[p];
        primeFact[n].second = nextComp;
    }

    ll numerator = n;
    ll denominator = 1;

    int currentPrimeChain = n;
    while (currentPrimeChain > 1) {
        int nextPrime = primeFact[currentPrimeChain].first;

        numerator *= nextPrime-1;
        denominator *= nextPrime;

        currentPrimeChain = primeFact[currentPrimeChain].second;
    }

    T[n] = numerator / denominator;
}

int main() {

    genPrimes();

    ll sum = 0;

    for (int i = 2; i < MAX; i++) {
        computeTotient(i);
        sum += T[i];
    }

    printf("%lld\n", sum);
    
    return 0;
}
