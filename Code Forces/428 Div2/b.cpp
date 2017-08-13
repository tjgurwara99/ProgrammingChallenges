#include <cstdio>
#include <algorithm>
using namespace std;

int N, K, A[100], remCount[8], spaceCount[5];

bool check() {
    int used = 0;

    for (int i = 0; i < K; i++) {
        used += A[i] / 8;
        remCount[A[i] % 8]++;
    }
    used += remCount[7];

    if (used > N) return false;

    spaceCount[4] = (N-used);
    spaceCount[2] = 2*(N-used);

    for (int i = 0; i < remCount[6]; i++) {
        if (spaceCount[4] && spaceCount[2]) {
            spaceCount[4]--;
            spaceCount[2]--;
        } else if (spaceCount[2] >= 3) {
            spaceCount[2] -= 3;
        } else if (spaceCount[4] >= 2) {
            spaceCount[4] -= 2;
            spaceCount[1]++;
        } else if (spaceCount[1] >= 6) {
            spaceCount[1] -= 6;
        } else {
            return false;
        }
    }

    for (int i = 0; i < remCount[5]; i++) {
        if (spaceCount[4] && spaceCount[1]) {
            spaceCount[4]--;
            spaceCount[1]--;
        } else if (spaceCount[4] && spaceCount[2]) {
            spaceCount[4]--;
            spaceCount[2]--;
        } else if (spaceCount[2] >= 2 && spaceCount[1]) {
            spaceCount[2] -= 2;
            spaceCount[1]--;
        } else if (spaceCount[2] >= 3) {
            spaceCount[2] -= 3;
        } else if (spaceCount[4] >= 2) {
            spaceCount[4] -= 2;
            spaceCount[2]++;
        } else if (spaceCount[1] >= 5) {
            spaceCount[1] -= 5;
        } else {
            return false;
        }
    }

    for (int i = 0; i < remCount[4]; i++) {
        if (spaceCount[4]) {
            spaceCount[4]--;
        } else if (spaceCount[2] >= 2) {
            spaceCount[2]--;
        } else if (spaceCount[1] >= 4) {
            spaceCount[1] -= 4;
        } else {
            return false;
        }
    }

    for (int i = 0; i < remCount[3]; i++) {
        if (spaceCount[4]) {
            spaceCount[4]--;
        } else if (spaceCount[2] && spaceCount[1]) {
            spaceCount[2]--;
            spaceCount[1]--;
        } else if (spaceCount[2] >= 2) {
            spaceCount[2] -= 2;
        } else if (spaceCount[1] >= 3) {
            spaceCount[1] -= 3;
        } else {
            return false;
        }
    }

    for (int i = 0; i < remCount[2]; i++) {
        if (spaceCount[2]) {
            spaceCount[2]--;
        } else if (spaceCount[1] >= 2) {
            spaceCount[1] -= 2;
        } else if (spaceCount[4]) {
            spaceCount[4]--;
            spaceCount[1]++;
        } else {
            return false;
        }
    }

    for (int i = 0; i < remCount[1]; i++) {
        if (spaceCount[1]) {
            spaceCount[1]--;
        } else if (spaceCount[2]) {
            spaceCount[2]--;
        } else if (spaceCount[4]) {
            spaceCount[4]--;
            spaceCount[2]++;
        } else {
            return false;
        }
    }

    return true;
}

int main() {

    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; i++) scanf("%d", &A[i]);

    if (check()) printf("YES\n");
    else         printf("NO\n");

    return 0;
}
