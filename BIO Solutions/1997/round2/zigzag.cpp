#include <cstdio>

int DP[15][15][2];
bool used[16];

int count(int below, int above, int zigUp) {

    if (below == 0 && above == 0) return 1;

    int& sum = DP[below][above][zigUp];
    if (sum == -1) {
        sum = 0;
        if (zigUp) {
            for (int i = 0; i < above; i++) sum += count(below+i, above-1-i, 0);
        } else {
            for (int i = 0; i < below; i++) sum += count(i, above+below-1-i, 1);
        }
    }

    return sum;
}

int main() {

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            DP[i][j][0] = DP[i][j][1] = -1;
        }
    }

    int B, N, nums[15];
    scanf("%d %d", &B, &N);
    N--;

    int numsAbove = B;
    int numsBelow = 0;

    for (int i = 0; i < B; i++) {
        if (i % 2) { // zig up
            int j = 0;
            while (N >= count(numsBelow + j, numsAbove-1-j, 0)) {
                N -= count(numsBelow + j, numsAbove-1-j, 0);
                j++;
            }

            numsAbove -= j+1;
            numsBelow += j;

            nums[i] = nums[i-1];
            while (j >= 0)  {
                nums[i]++;
                if (!used[nums[i]]) j--;
            }
            used[nums[i]] = true;

        } else { // zig down
            int j = 0;
            while (N >= count(j, numsAbove+numsBelow-j-1, 1)) {
                N -= count(j, numsAbove+numsBelow-1-j, 1);
                j++;
            }

            numsAbove += numsBelow-j-1;
            numsBelow = j;

            nums[i] = 0;
            while (j >= 0) {
                nums[i]++;
                if (!used[nums[i]]) j--;
            }
            used[nums[i]] = true;
        }

        if (nums[i] < 10) printf("%d", nums[i]);
        else printf("%c", 'a'+(nums[i]-10));
    }
    printf("\n");

    return 0;
}
