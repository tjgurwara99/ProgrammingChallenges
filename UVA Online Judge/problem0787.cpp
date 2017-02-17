#include <cstdio>
using namespace std;

#define ll long long

int main() {
    
    int A[505], N, returnFlag = 1;
    
    while (returnFlag != EOF) {
        
        N = 0;
        while ((returnFlag = scanf("%d", &A[N])) != EOF && A[N] != -999999) {
            N++;
        }
        if (returnFlag == EOF) break;
        
        ll maxProduct = -999999;
        
        for (int i = 0; i < N; i++) {
            ll prod = 1;
            for (int j = i; j < N; j++) {
                prod *= A[j];
                if (prod > maxProduct) maxProduct = prod; 
            }
        }
        
        printf("%lld\n", maxProduct);
    }
    
    return 0;
}