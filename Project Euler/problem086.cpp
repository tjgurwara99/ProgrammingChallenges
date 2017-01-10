#include <cstdio>
#include <cmath>
using namespace std;

int n;

inline int perfectSquare() {
    int h = n & 0xF; // last hexadecimal "digit"
    if (h > 9) return 0; // return immediately in 6 cases out of 16.

    // Take advantage of Boolean short-circuit evaluation
    if ( h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8 ) {
        // take square root if you must
        int t = (int) floor( sqrt((double) n) + 0.5 );
        return t*t == n;
    }
    return 0;
}

inline int countUntil(int M) {
    int count = 0, a2, b2, a, b, c;
    for (a = 1; a <= M; ++a) {
        a2 = a*a;
        for (b = a; b <= M; ++b) {
            b2 = a2 + b*b + ((a*b) << 1);
            for (c = b; c <= M; ++c) {
                n = b2+c*c;
                if (perfectSquare()) ++count;
            }
        }
    }
    return count;
} 

int main() {

    int lower = 1000, upper = 2000;

    /* Binary search for the answer */
    while (upper > lower) {
        int mid = lower + (upper - lower) / 2;
        printf("Range %d to %d\n", lower, upper);
        if (countUntil(mid) > 1000000) {
           upper = mid-1;
        } else {
           lower = mid+1;
        }
    }

    printf("%d\n", lower);

    return 0;
}
