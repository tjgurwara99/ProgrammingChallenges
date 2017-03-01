#include <cstdio>
using namespace std;

#define ll long long

int A, B, C, grid[20][20][20];

int main() {
    
    int T;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d %d", &A, &B, &C);
        
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                for (int k = 0; k < C; k++) {
                    scanf("%d", &grid[i][j][k]);
                }
            }
        }
    }
    
    return 0;
}