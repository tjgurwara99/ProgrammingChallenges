#include <cstdio>
using namespace std;

#define MOD 1000000007L
#define K 10
#define N 100

bool isComposite[N+1];

long partitions[10000][20]; // partitions[i][j] = partition n into j sums
long stirling[10000][20];

int main() {

    // Plan:
    // - Compute the prime facorisation (easy)
    // - Then sum all the primes to s
    // - Count the number of ways to partition s into K plus s into K-1 (with 1 included)

    int primeTotal = 0;
    int primeCount = 0;

    isComposite[0] = isComposite[1] = true;
    for (int i = 2; i <= N; i++) {
        if (isComposite[i]) continue;

        int count = 0;
        for (int j = N/i; j; j /= i) count += j;

        primeTotal += i*count;
        primeCount += count;

        for (int j = i*i; j <= N; j += i) isComposite[j] = true;
    }

    for (int i = 1; i <= primeTotal; i++) stirling[i][1] = stirling[i][i] = 1;

    for (int i = 1; i <= primeTotal; i++) {
        for (int j = 2; j <= 15; j++) {
            stirling[i][j] = stirling[i-1][j]*j + stirling[i-1][j-1];
            stirling[i][j] %= MOD;
        }
    }

    for (int i = 1; i <= primeTotal; i++) {
        partitions[i][1] = 1;
        if (i < 16) partitions[0][i] = partitions[i][i] = 1;
    }

    for (int i = 1; i <= primeTotal; i++) {
        for (int j = 2; j <= 15 && j < i; j++) {
            for (int k = 1; k <= j; k++) { 
                partitions[i][j] += partitions[i-j][k];
                partitions[i][j] %= MOD;
            }
        }
    }
    
    printf("%d %d\n", primeTotal, primeCount);
    printf("%ld %ld\n", stirling[primeCount][K], stirling[primeTotal][K]);
    //printf("%ld\n", (partitions[primeTotal][K] + partitions[primeTotal][K-1] ) % MOD) ;
    //printf("%ld\n", (partitions[primeCount][K] + partitions[primeCount][K-1] ) % MOD) ;

    return 0;
}
