#include <cstdio>

#define MAXN 1024
int N, R[MAXN][2];
int DP[MAXN][MAXN + 1][3];
// DP => [left pos (0 to N-1), crops left (0-N), right pos state]
// right states: 0 => rightPos=leftPos, 1=>rightPos=leftPos+1, 2=>rightPos=leftPos-1
// (space saving because other states reduce down to one of these 3)

int maxFertility(int leftPos, int cropsLeft, int rightState) {
    
    // Base cases
    if (cropsLeft == 0 || leftPos == N ||
        (leftPos == N-1 && rightState == 1)
        ) return 0;
    
    int& state = DP[leftPos][cropsLeft][rightState];
    
    if (state == -1) {
        // Both are equal
        if (rightState == 0) {
            
            // Choose across
            int a = R[leftPos][0] + R[leftPos][1] + maxFertility(leftPos+1, cropsLeft-1, 0);
            
            // Choose left down and right down
            int b = 0;
            if (cropsLeft >= 2 && leftPos < N-1) {
                b = R[leftPos][0] + R[leftPos][1] + R[leftPos+1][0] + R[leftPos+1][1];
                b += maxFertility(leftPos+2, cropsLeft-2, 0);
            }
            
            // Choose only left down
            int c = 0;
            if (leftPos < N-1) {
                c = R[leftPos][0] + R[leftPos+1][0];
                c += maxFertility(leftPos+2, cropsLeft-1, 2);
            }
            
            // Choose only right down
            int d = 0;
            if (leftPos < N-1) {
                d = R[leftPos][1] + R[leftPos+1][1];
                d += maxFertility(leftPos+1, cropsLeft-1, 1);
            }
            
            // Choose nothing
            int e = maxFertility(leftPos+1, cropsLeft, 0);
            
            if (a > state) state = a;
            if (b > state) state = b;
            if (c > state) state = c;
            if (d > state) state = d;
            if (e > state) state = e;
            
        // Right is one ahead
        } else if (rightState == 1) {
            
            // Pick left down
            int a = 0;
            if (leftPos < N-1) {
                a = R[leftPos][0] + R[leftPos+1][0];
                a += maxFertility(leftPos+2, cropsLeft-1, 2);
            }
            
            // Pick nothing
            int b = maxFertility(leftPos+1, cropsLeft, 0);
            
            if (a > state) state = a;
            if (b > state) state = b;
            
        // Right is one behind
        } else {
            
            // Pick right down
            int a = R[leftPos-1][1] + R[leftPos][1];
            a += maxFertility(leftPos, cropsLeft-1, 1);
            
            // Pick nothing
            int b = maxFertility(leftPos, cropsLeft, 0);
            
            if (a > state) state = a;
            if (b > state) state = b;
        }
    }
    
    return state;
}

int main() {
    int numCrops;
    scanf("%d", &N);
    scanf("%d", &numCrops);
    for (int i = 0; i < N; i++)  scanf("%d %d", &R[i][0], &R[i][1]);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= numCrops; j++) {
            DP[i][j][0] = DP[i][j][1] = DP[i][j][2] = -1;
        }
    }
    
    printf("%d\n", maxFertility(0, numCrops, 0));
    return 0;
}
