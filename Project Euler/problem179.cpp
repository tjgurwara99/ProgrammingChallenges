#include <cstdio>

#define MAXN 10000000
#define ll long long

bool isComposite[MAXN+1];
int primeFactor[MAXN+1];

ll numDivisors(int p) {
    ll ans = 1;
    while (p != 1) {
        int pdiv = primeFactor[p];
        int cnt = 1;
        while (primeFactor[p /= pdiv] == pdiv) {
            cnt++;
        }
        ans *= (1 + cnt);
    }
    return ans;
}

ll ND[MAXN+1];

int main() {
    
    for (int i = 1; i <= MAXN; i++) primeFactor[i] = i;
    
    isComposite[0] = isComposite[1] = true;
    for (int i = 2; i <= MAXN; i++) {
        if (isComposite[i]) continue;
        for (int j = i; j <= MAXN; j += i) {
            isComposite[j] = true;
            primeFactor[j] = i;
        }
    }
    
    for (int i = 1; i <= MAXN; i++) ND[i] = numDivisors(i);
    
    int ans = 0;
    for (int i = 2; i < MAXN; i++) {
        if (ND[i] == ND[i+1]) {
            ++ans;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}