#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100000;
const int E = 10000;

bool isComposite[MAXN+1];
vector<int> primes;
pair<int, int> rads[MAXN+1];

inline int rad(int n) {
    int r = 1;
    for (int p: primes) {
        if (p*p > n) break;
        if (!(n % p)) {
            r *= p;
            while (!(n % p)) n /= p;
        }
    }
    r *= n;
    return r;
}

int main() {
    
    isComposite[0] = isComposite[1] = true;
    for (int i = 2; i <= MAXN; i++) {
        if (isComposite[i]) continue;
        primes.push_back(i);
        if (MAXN/i < i) continue;
        for (int j = i*i; j <= MAXN; j += i) isComposite[j] = true;
    }
    
    for (int i = 1; i <= MAXN; i++) {
        rads[i-1].first = rad(i);
        rads[i-1].second = i;
    }
    sort(rads, rads+MAXN);
    cout << rads[E-1].second << endl;
    
    return 0;
}