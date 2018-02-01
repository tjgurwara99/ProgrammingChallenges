#include <bits/stdc++.h>
using namespace std;

#define MOD ((int)1e9+7)
#define ll long long

string N;
int NCR[1005][1005], steps[1005], bitDP[1005][1005], K;

inline int bitSum(int n) {
    int count = 0;
    for (; n; n >>= 1) if (n&1) ++count;
    return count;
}

int main() {
    
    cin >> N >> K;
    int M = (int)N.size();
    
    if (K == 0) {
        cout << 1 << endl;
        return 0;
    }
    
    for (int i = 0; i <= 1000; i++) {
        NCR[i][0] = NCR[i][i] = 1;
        for (int j = 1; j < i; j++) NCR[i][j] = (NCR[i-1][j] + NCR[i-1][j-1]) % MOD;
    }
    
    for (int i = 0; i <= M; i++) bitDP[i][0] = 1;
    for (int i = M-1; i >= 0; --i) {
        if (N[i] == '0') {
            for (int b = 1; i+b <= M; b++) {
                bitDP[i][b] = bitDP[i+1][b];
            }
        } else {
            for (int b = 1; i+b <= M; b++) {
                bitDP[i][b] = (bitDP[i+1][b-1] + NCR[M-1-i][b]);
            }
        }
    }
    
    if (K == 1) {
        cout << bitDP[0][1] << endl;
        return 0;
    }
    
    steps[1] = 0;
    int ans = 0;
    for (int i = 2; i <= 1000; i++)  {
        steps[i] = 1 + steps[bitSum(i)];
    
        if (steps[i] == K-1) {
            ans = (ans + bitDP[0][i]) % MOD;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}