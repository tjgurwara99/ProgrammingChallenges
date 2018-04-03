/*
ID: basimkh1
PROG: theme
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int N, A[5001];

int main() {
    
    freopen("theme.in", "r", stdin); freopen("theme.out", "w", stdout);
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    
    int maxLength = 1, len;
    
    for (int i = 0; i < N; i++) {
        for (int j = i+maxLength; j < N-maxLength; j++) {
            len = 0;
            while (i+len < j && j+len < N && A[j+len]-A[i+len] == A[j]-A[i]) {
                len++;
            }
            if (len > maxLength) maxLength = len;
        }
    }
    
    cout << ((maxLength < 5) ? 0 : maxLength) << endl;
    
    return 0;
}