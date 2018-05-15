#include <cstdio>
#include <vector>
using namespace std;

int egcd(int a, int b, int& x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int q = a/b, r = a-q*b, x1, y1, gcd = egcd(b, r, x1, y1);
    x = y1;
    y = x1 - q * y1;
    return gcd;
}

int modInv(int a, int p) {
    int n, x, g = egcd(a, p, n, x);
    return n % p;
}

const int N = 100000000;

bool isComposite[N];
vector<int> primes;

int main() {
    
    primes.push_back(2);
    for (int i = 3; i < N; i+=2) {
        if (isComposite[i]) continue;
        primes.push_back(i);
        if (N / i < i) continue;
        for (int j = i*i; j < N; j += i) isComposite[j] = true;
    }
    
    long ans = 0;
    for (int i = 2; i < (int)primes.size(); i++) {
        long p = primes[i], total = p-1, acc = p-1;
        for (int j = 2; j <= 5; j++) {
            acc = (acc * modInv(p-j+1, p)) % p; 
            total += acc;
        }
        total %= p;
        if (total < 0) total += p;
        ans += total;
    }
    printf("%ld\n", ans);
    
    return 0;
}