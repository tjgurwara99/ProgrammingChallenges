#include <cstdio>
#include <vector>
using namespace std;

#define LIMIT 50000000
#define SQRTLIMIT 8000

bool isComposite[SQRTLIMIT];
bool canBeMade[LIMIT];
vector<int> primes[4];

int main() {

    isComposite[0] = isComposite[1] = true;
    for (int i = 2; i < SQRTLIMIT; i++) {
        if (isComposite[i]) continue;
        primes[0].push_back(i);
        primes[1].push_back(i*i);
        primes[2].push_back(i*i*i);
        primes[3].push_back(i*i*i*i);
        for (int j = i*i; j < SQRTLIMIT; j += i) isComposite[j] = true;
    }

    int count = 0;

    for (int i = 0; primes[1][i] < LIMIT; i++) {
        int s = primes[1][i];
        for (int j = 0; primes[2][j] + s < LIMIT; j++) {
            s += primes[2][j];
            for (int k = 0; primes[3][k] + s < LIMIT; k++) {
                int l = s + primes[3][k]; 
                if (!canBeMade[l]) {
                    //printf("%d %d %d %d\n", i, j, k , l);
                    canBeMade[l] = true;
                    count++;
                }
            }
            s -= primes[2][j];
        }
    }

    printf("%d\n", count);

    return 0;
}
