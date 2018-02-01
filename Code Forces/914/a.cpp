#include <iostream>
#include <cmath>
using namespace std;

inline bool isSquare(int n) {
    if (n < 0) return false;
    int s = sqrt(n);
    return s*s == n;
}

int main() {
    
    int n, A[2000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    
    int ans = -1e8;
    for (int i = 0; i < n; i++) {
        if (A[i] > ans && !isSquare(A[i])) ans = A[i];
    }
    
    cout << ans << endl;
    return 0;
}