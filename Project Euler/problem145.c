/* Correct answer in 3s  (under -O2 optimisation) */
#include <stdio.h>

int main() {

    int count = 0, i, c, j, rev;
    int digits[10], l = 1;
    digits[0] = 1;

    for (i = 1; i < 1000000000; ++i) {

        if (digits[0]) {
            c = 0;
            for (j = 0; j < l; j++) {
                rev = digits[j]+digits[l-j-1]+c;
                if (!(rev & 1)) break;
                c = rev >= 10;
            }
            if (j == l) ++count;
        }

        for(j = 0; digits[j] == 9; ++j ) digits[j] = 0;
        if (j == l) digits[l++] = 1;
        else digits[j]++;
    }

    printf("%d\n", count);
    return 0;
}
