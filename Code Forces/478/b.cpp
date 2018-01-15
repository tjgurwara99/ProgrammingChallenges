#include <iostream>
using namespace std;

#define ll long long
int N, M;

inline ll pairs(ll n) { return (n*n - n) / 2; } 

int main() {
    
    cin >> N >> M;
    
    ll maxPairs = pairs(N - M + 1);
    
    int modVal = N % M;
    ll minPairs = pairs(N/M)*(M-modVal) + pairs(N/M+1)*modVal;
    
    cout << minPairs << " " << maxPairs << endl;
    
    return 0;
}