#include <bits/stdc++.h>
using namespace std;

#define MAXN 123456
#define ll long long

int N, V[MAXN], T[MAXN], removeCount[MAXN];
ll preV[MAXN], preT[MAXN], dayMelt[MAXN];

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &V[i]);
    for (int i = 0; i < N; i++) scanf("%d", &T[i]);
    
    for (int i = 0; i < N; i++) {
        preV[i+1] = preV[i] + V[i];
        preT[i+1] = preT[i] + T[i];
    }
    
    for (int i = 0; i < N; i++) {
        int j = (int)(lower_bound(preT, preT+N+1, preT[i] + V[i]) - preT);
        dayMelt[j-1] += V[i] - (preT[j] - preT[i]);
        // cout << i << " " << j << " " << dayMelt[j-1] << endl;
        removeCount[j]++;
    }
    
    int pileCount = 0;
    for (int i = 0; i < N; i++) {
        pileCount++;
        pileCount -= removeCount[i];
        dayMelt[i] += ((ll)T[i]) * pileCount;
        printf("%lld ", dayMelt[i]);
    }
    printf("\n");
    
    return 0;
}