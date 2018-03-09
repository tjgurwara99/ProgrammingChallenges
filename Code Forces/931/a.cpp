#include <bits/stdc++.h>
using namespace std;

inline int tri(int n) { return (n*(n+1))/2; }

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    if (a > b) swap(a,b);
    
    int minCost = tri(b-a);
    for (int c = a; c <= b; c++) {
        minCost = min(minCost, tri(c-a)+tri(b-c));
    }
    
    cout << minCost << endl;
    return 0;
}