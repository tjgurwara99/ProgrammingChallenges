#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000

bool isComposite[MAXN];
vector<int> primes;

inline int maxPrimeFactor(int n) {
    int bf = 1;
    for (int i = 0; primes[i]*primes[i] <= n && i < (int)primes.size(); i++) {
        if (n % primes[i] == 0) {
            bf = primes[i];
            while (n % bf == 0) n /= bf;
        }
    }
    return max(n, bf);
}

int main() {
    
    int x2;
    cin >> x2;
    
    isComposite[0] = isComposite[1] = true;
    for (int i = 2; i < MAXN; i++) {
        if (isComposite[i]) continue;
        primes.push_back(i);
        for (int j = i*i; j < MAXN; j += i) isComposite[j] = true;
    }
    
    int lb = x2 - maxPrimeFactor(x2) + 1;
    int ans = lb;
    
    for (int i = lb; i < x2; i++) {
        int pf = maxPrimeFactor(i);
        if (pf != i) {
            int newAns = i - pf + 1;
            if (newAns < ans) ans = newAns;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}