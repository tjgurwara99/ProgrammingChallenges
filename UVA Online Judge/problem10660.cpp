#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int population[25];

inline int getCost(int positions[]) {
    int cost = 0;
    for (int p = 0; p < 25; p++) {
        int minCost = 10000;
        int r = p/5, c = p%5;
        for (int i = 0; i < 5; i++) {
            int nr = positions[i]/5, nc = positions[i]%5;
            minCost = min(minCost, abs(nr - r) + abs(nc- c));
        }
        cost += minCost * population[p];
    }
    return cost;
}

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {
        int n, r, c;
        scanf("%d", &n);

        for (int i = 0; i < 25; i++) population[i] = 0;

        while (n--) {
            scanf("%d %d", &r, &c);
            scanf("%d", &population[r*5+c]);
        }

        int bestPos[5], minCost = 100000;

        for (int a = 0; a < 25; a++) {
            for (int b = a+1; b < 25; b++) {
                for (int c = b+1; c < 25; c++) {
                    for (int d = c+1; d < 25; d++) {
                        for (int e = d+1; e < 25; e++) {
                            int pos[] = { a, b, c, d, e };
                            int cost = getCost(pos);

                            if (cost < minCost) {
                                minCost = cost;
                                for (int i = 0; i < 5; i++) bestPos[i] = pos[i];
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++) printf("%d ", bestPos[i]);
        printf("%d\n", bestPos[4]);
    }

    return 0;
}
