#include <bits/stdc++.h>
using namespace std;

int main() {

    int W, L, A[200000];
    cin >> W >> L;
    for (int i = 1; i < W; i++) {
        cin >> A[i];
        A[i] += A[i-1];
    }
    
    int ans = INT_MAX;
    for (int i = 1; i <= W-L; i++) ans = min(ans, A[i+L-1]-A[i-1]);
    cout << ans << endl;
    
    return 0;
}