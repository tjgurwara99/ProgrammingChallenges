/* Correct answer in 15s  (under -O2 optimisation) */
#include <stdio.h>

int main() {

    int count = 0, i, r, j, rev;

    for (i = 1; i < 1000000000; ++i) {
        if (i % 10 == 0) continue;

        r = 0;
        for (j = i; j; j /= 10) r = (r * 10) + (j % 10);
        r += i;

        rev = 1;
        for (; r; r /= 10) {
            if (!(r & 1)) {
                rev = 0;
                break;
            }
        }

        if (rev) count++;
    }

    printf("%d\n", count);
    return 0;
}
