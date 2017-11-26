#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD (int)(1e9+7)
#define MAXN 123456

int N, A[71], mask[71], pow2[MAXN];
map<int,ll> DP[71];
vector<int> primes;

ll count(int i, int p) {
    
    if (i > 70) return (p == 0) ? 1 : 0;
    
    if (DP[i].count(p) == 0) {
        ll evens = count(i+1, p);
        
        if (A[i]) {
            // (evens + odds) * (2 ^ (A[i] - 1))
            ll odds = count(i+1, p ^ mask[i]);
            ll total = (evens + odds) % MOD;
            DP[i][p] = (total * pow2[A[i] - 1]) % MOD;
        } else {
            DP[i][p] = evens;
        }
    }
    
    return DP[i][p];
}

int main() {
    
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[a]++;
    }
    
    pow2[0] = 1;
    for (int i = 1; i <= N; i++) pow2[i] = (pow2[i-1] * 2) % MOD;
    
    for (int i = 2; i < 70; i++) {
        bool prime = true;
        for (int j = 2; j*j <= i; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) primes.push_back(i);
    }
    
    for (int i = 1; i <= 70; i++) {
        for (int j = 0; j < (int)primes.size(); j++) {
            int pc = 0;
            for (int a = i; a % primes[j] == 0; a /= primes[j])  pc++;
            
            if (pc % 2) {
                mask[i] |= (1 << j);
            }
        }
    }
    
    cout << count(1,0)-1 << endl;
    
    return 0;
}