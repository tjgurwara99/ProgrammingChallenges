#include <cstdio>
using namespace std;

bool hasLeft(int x1, int y1, int x2, int y2) {
    if (x1 > 0 && x2)
}

//
//  Use the cross product to determine which
//  side of the triangle each point is opn
//


int main () {
    
    int x[3], y[3];
    
    FILE *f = fopen("p102_triangles.txt", "r");
    
    for (int i = 0; i < 1000; i++) {
        fscanf(f, "%d,%d,%d,%d,%d,%d", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
        
        // Check left
        
    }
    
    
    fclose(f);
    
    return 0;
}