#include <iostream>
using namespace std;

#define NC2(n) (n*(n+1)/2)
long long DP[2][200001];

int main() {
    
    int R, G;
    cin >> R >> G;
    
    int height = 1;
    while (NC2(height) <= R+G) height++;
    height--;
    
    for (int r = 0; r <= R; r++) DP[0][r] = 1;
    for (int h = 1; h <= height; h++) {
        int a = h&1, b = 1-(h&1);
        for (int r = 0; r <= R; r++) {
            int g = G - (NC2(height) - NC2(h) - (R - r));
            
            DP[a][r] = 0;
            if (r >= h) DP[a][r] += DP[b][r-h];
            if (g >= h) DP[a][r] += DP[b][r];
            DP[a][r] %= 1000000007;
        }
    }
    
    cout << DP[height&1][R] << endl;
    
    return 0;
}