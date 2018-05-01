#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N, K;
    cin >> N >> K;
    
    bool A[100][100];
    int count[100][100];
    
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        
        for (int j = 0; j < N; j++) {
            A[i][j] = s[j] == '.';
            count[i][j] = 0;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N-K; j++) {
            bool h = true, v = true;
            for (int k = 0; k < K; k++) {
                if (!A[i][j+k]) h = false;
                if (!A[j+k][i]) v = false;
            }
            for (int k = 0; k < K; k++) {
                if (h) count[i][j+k]++;
                if (v) count[j+k][i]++;
            }
        }
    }
    
    
    int mi = 0, mj = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (count[i][j] > count[mi][mj]) {
                mi = i;
                mj = j;
            }
        }
    }
    
    cout << (mi+1) << " " << (mj+1) << endl;
    
    return 0;
}