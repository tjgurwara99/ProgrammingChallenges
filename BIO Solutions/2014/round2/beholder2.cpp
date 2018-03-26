#include <bits/stdc++.h>
using namespace std;

#define MAXN 1100

int DP[MAXN][MAXN];

int main() {
    
    string input;
    cin >> input;
    
    int N = (int)input.size(), ans = 0;
    
    for (int i = 0; i < N; i++) DP[i][1] = 1;
    for (int l = 2; l <= N; l++) {
        for (int i = 0; i < N; i++) {
            DP[i][l] = DP[i][l-1];
            if (input[i] == input[i+l-1]) {
                DP[i][l] = max(DP[i][l], DP[i+1][l-2] + 2);
            }
            ans = max(ans, DP[i][l]);
        }
    }
    
    cout << N-ans << endl;
    
    return 0;
}