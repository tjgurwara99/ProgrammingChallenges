#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N, A[400];
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    
    int minDiff = 360;
    
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += A[j];
            minDiff = min(minDiff, abs((360-sum) - sum));
        }    
    }
    
    cout << minDiff << endl;
    
    return 0;
}