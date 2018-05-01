#include <iostream>
using namespace std;

#define ll long long
#define TARGET ((long long)1e10)
#define MAXN 300000

bool isComposite[MAXN+1];
int primeCount;

int main() {
    
    isComposite[0] = isComposite[1] = true;
    for (int i = 2; i <= MAXN; ++i) {
        if (isComposite[i]) continue;
        
        if (++primeCount % 2) {
            ll test = ((ll)((2 *primeCount) % i)) * i;
            if (test > TARGET) {
                cout << primeCount << "\n";
                break;
            }
        }
        
        if (MAXN/i < i) continue;
        for (int j = i*i; j <= MAXN; j+=i) isComposite[j] = true;
    }
    
    return 0;
}