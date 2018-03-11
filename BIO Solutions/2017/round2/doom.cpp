#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 66000

int N;
ll T, P[MAXN];

int main() {
    
    scanf("%d %lld", &N, &T);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &P[i]);
        P[i] += P[i-1];
    }
    
    sort(P, P+N+1);
    
    ll bestAnswer = ((ll)1) << 62;
    
    for (int i = 0; i < N; i++) {
        int j = (int)(lower_bound(P+i, P+N+1, P[i]+T)-P);
        if (j > N) break;
        
        ll profit = P[j] - P[i];
        if (profit < bestAnswer) bestAnswer = profit;
    }
    
    printf("%lld\n", bestAnswer);
    
    return 0;
}