/* Correct answer */
#include <cstdio>
using namespace std;

int crossProduct(int x1, int y1, int x2, int y2) {
    return x1*y2 - y1*x2;
}

int sign(int x) {
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
}

int x[3], y[3];

inline bool hasOrigin() {
    int a = sign(crossProduct(x[1] - x[0], y[1] - y[0], -x[0], -y[0]));
    int b = sign(crossProduct(x[2] - x[1], y[2] - y[1], -x[1], -y[1]));
    int c = sign(crossProduct(x[0] - x[2], y[0] - y[2], -x[2], -y[2]));
    return a == b && b == c;
}

int main () {
    FILE *f = fopen("p102_triangles.txt", "r");
    int count = 0;
    
    for (int i = 0; i < 1000; i++) {
        fscanf(f, "%d,%d,%d,%d,%d,%d", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
        if (hasOrigin()) count++;
    }
    
    printf("Total: %d\n", count);
    fclose(f);
    
    return 0;
}
