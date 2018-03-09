#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int N, X[MAXN], counts[3];

int main() {
    
    int l = 1000000, u = -1000000;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        l = min(l, X[i]);
        u = max(u, X[i]);
    }
    
    if (u-l < 2) {
        cout << N << endl;
        for (int i = 0; i < N; i++) cout << X[i] << " ";
        cout << endl;
        return 0;
    }
    
    for (int i = 0; i < N; i++) counts[X[i] - l]++;
    
    int aChange = 2*min(counts[0], counts[2]);
    int bChange = (counts[1]/2)*2;
    
    if (aChange > bChange) {
        cout << N-aChange << endl;
        counts[0] -= aChange/2;
        counts[1] += aChange;
        counts[2] -= aChange/2;
    } else {
        cout << N-bChange << endl;
        counts[0] += bChange/2;
        counts[1] -= bChange;
        counts[2] += bChange/2;
    }
    
    for (int i = 0; i < counts[0]; i++) cout << l << " ";
    for (int i = 0; i < counts[1]; i++) cout << l+1 << " ";
    for (int i = 0; i < counts[2]; i++) cout << l+2 << " ";
    cout << endl;
    
    return 0;
}