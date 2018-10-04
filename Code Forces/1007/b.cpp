#include <iostream>
using namespace std;

int A, B, C, t;

inline int countFactors(int p) {
    int c = 2, i = 2;
    for (; i*i < p; i++) {
        if (p % i == 0) c += 2;
    }
    if (i*i == p) c++;
    return c;
}

inline int gcd(int p, int q) {
    int c;
    while (q) {
        c = p % q;
        p = q;
        q = c;
    }
    return p;
}

int main() {
    
    /* TODO: Incomplete */
    
    cin >> t;
    while (t--) {
        cin >> A >> B >> C;
        int a = countFactors(A), b = countFactors(B), c = countFactors(C);
        int ab = countFactors(gcd(A,B)), bc = countFactors(gcd(B,C)), ac = countFactors(gcd(A,C));
        int abc = countFactors(gcd(A, gcd(B, C)));
        
        // for plane ab
        int ans = (a*b - ab) / 2 + ab;
        
        int ans = (a*b*c - ab );
        
        int ans = a * b * c;
        ans -= ab * c;
        ans -= 3 * ab;
        ans -= 3 * bc;
        
        
    }
    
    return 0;
}