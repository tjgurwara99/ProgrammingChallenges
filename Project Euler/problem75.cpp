/* Correct answer in 42ms */
#include <cstdio>
#include <cmath>
using namespace std;

#define MAX 1500000

inline int gcd(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int numRightTriangles[MAX+1];

int main() {

    // Using Euclid's formula for generating
    // Pythagorean triplets

    for (int m = 1; m*m < MAX; m++) {
        for (int n = 1 + (m % 2); n < m; n += 2) {
            if (gcd(m, n) != 1) continue;

            int a = m*m - n*n;
            int b = 2*m*n;
            int c = m*m + n*n;
            int l = a+b+c;

            for (int i = l; i <= MAX; i += l) numRightTriangles[i]++;
        }
    }

    int count = 0;
    for (int i = 1; i <= MAX; i++) {
        if (numRightTriangles[i] == 1) count++;
    }
    printf("%d\n", count);

    return 0;
}
