#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXW 123456

int W, R;
int A[MAXW];

inline int mapPoint(ll p) {
    int x = (int)(p % (2*W));
    if (x < 0) x = -x;
    if (x >= W) x = (W - 1) - (x - W + 1);
    return x;
}
    
int main() {
    
    scanf("%d %d", &W, &R);
    
    int p;
    while (scanf("%d", &p), p != -1) {
        int a = mapPoint((ll)p + R);
        int b = mapPoint((ll)p - R);
        
        if (a > b) swap(a, b);
        for (; a <= b; a += 2) A[a] ^= 1;
    }
    
    int ans = 0;
    for (int i = 0; i < W; i++) if (A[i]) ++ans;
    
    cout << ans << endl;
    
    return 0;
}