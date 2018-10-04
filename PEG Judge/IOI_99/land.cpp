#include <iostream>
using namespace std;

#define MAXD 700
#define LMAXD 10

int N, M, C, A[MAXD][MAXD];

int main() {
    
    cin >> N >> M >> C;
    for (int y = N-1; y >= 0; y--) {
        for (int x = 0; x < M; x++) cin >> A[y][x];
    }
    
    
    return 0;
}