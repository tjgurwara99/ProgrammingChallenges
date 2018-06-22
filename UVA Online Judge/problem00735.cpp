#include <cstdio>
#include <vector>
using namespace std;

bool possible[61];

int main() {
    
    possible[0] = possible[50] = true;
    for (int i = 1; i <= 20; i++) {
        for (int k = 1; k < 4; k++) possible[k*i] = true;
    }
    
    vector<int> ds;
    for (int i = 0; i <= 60; i++) if (possible[i]) ds.push_back(i);
    int D = (int)ds.size();
    
    int n;
    while (scanf("%d", &n), n > 0) {
        int cs = 0, ps = 0;
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < D; j++) {
                for (int k = 0; k < D; k++) {
                    if (ds[i] + ds[j] + ds[k] == n) ps++;
                }
            }
        }
        for (int i = 0; i < D; i++) {
            for (int j = i; j < D; j++) {
                for (int k = j; k < D; k++) {
                    if (ds[i] + ds[j] + ds[k] == n) cs++;
                }
            }
        }
        if (ps) {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, cs);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, ps);
        } else {
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
        }
        for (int i = 0; i < 70; i++) printf("*");
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}