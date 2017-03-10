#include <iostream>
#include <cmath>
using namespace std;

#define ll long long
#define LIM 1000000000

int main() {
    
    int maxA = LIM/3 + 2;
    int maxK = maxA/2 + 1;
    
    ll total = 0;
    
    for (ll k = 1; k <= maxK; k++) {
        ll h2 = 3*k*k+4*k+1;
        ll h = (ll)sqrt(h2);
        
        if (h*h == h2) {
            total += 6*k+2;
            continue;
        }
        
        h2 = 3*k*k+2*k;
        h = (ll)sqrt(h2);
        
        if (h*h == h2) {
            total += 6*k+4;
        }
    }
    
    cout << total << endl;
    
    return 0;
}