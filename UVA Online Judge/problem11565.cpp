#include <cstdio>
#include <cmath>
#include <cstdlib>

int main() {
    
    int t, A, B, C;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d %d", &A, &B, &C);
        bool found = false;
        for (int x = -B; x <= B; x++) {
            if (x == 0 || B % abs(x)) continue;
            int a = A-x;
            int b = B/x;
            
            int disc = a*a - 4*b;
            if (disc < 0) continue;
            
            int s = (int)sqrt(disc);
            if (s*s != disc) continue;
            if ((s + a) % 2) continue;
            
            int y = (a-s)/2, z = (a+s)/2;
            if (x == y || x == z || y == z) continue;
            
            if (x*x +y*y + z*z == C) {
                printf("%d %d %d\n", x, y, z);
                found = true;
                break;
            }
        }
        if (!found) printf("No solution.\n");
    }
}