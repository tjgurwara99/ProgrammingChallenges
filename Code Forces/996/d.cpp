#include <iostream>
#include <algorithm>
using namespace std;

int N, A[500];

int main() {
    
    cin >> N;
    for (int i = 0; i < 2*N; i++) cin >> A[i];
    
    int ans = 0;
    
    for (int p = 0; p < N; p++) {
        int x = A[2*p];
        int i = 2*p+1;
        while (A[i] != x) i++;
        for (; i > 2*p+1; --i) {
            swap(A[i], A[i-1]);
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}