#include <iostream>
#include <algorithm>
using namespace std;

int N, A[200000];

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    
    sort(A, A+N);
    
    int ans = 1;
    for (int i = 0; i < N; i++) {
        int j = 0;
        while (i+j < N && A[i+j] == A[i]) j++;
        if (j > ans) ans = j;
        i += j-1;
    }
    cout << N-ans << endl;
    return 0;
}