/* Correct answer in 2.667s */
#include <cstdio>
#include <vector>
using namespace std;

#define ll long long
#define PMAX 100000
#define MAX 10000000

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

inline bool isPerm(int a, int b) {
    short count[10];
    for (int i = 0; i < 10; i++) count[i] = 0;

    for (; a; a /= 10) count[a % 10]++;
    for (; b; b /= 10) count[b % 10]--;

    for (int i = 0; i < 10; i++) if (count[i]) return false;
    return true;
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

    int minRatioN = -1;
    double minRatio = 2000000;

    for (int i = 2; i < MAX; i++) {
        computeTotient(i);
        double ratio = ((double) i) / T[i];

        if (ratio < minRatio && isPerm(i, T[i])) {
            minRatio = ratio;
            minRatioN = i;
        }
    }

    printf("t(%d) = %lld\n", minRatioN, T[minRatioN]);
    
    return 0;
}
