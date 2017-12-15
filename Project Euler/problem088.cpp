#include <bits/stdc++.h>
using namespace std;

#define N 12000

int minProductSum[N+1];
bool seen[2*N+2];

void factGen(int minFactor, int sum, int product, int numFactors) {
    if (product >= sum) {
        int k = numFactors + (product - sum);
        if (k <= N && product < minProductSum[k]) minProductSum[k] = product;
    }
    
    for (int i = minFactor; product*i < 2*N; i++) {
        factGen(i, sum + i, product * i, numFactors + 1);
    }
}

int main() {
    for (int i = 0; i <= N; i++) minProductSum[i] = INT_MAX;
    
    factGen(2, 0, 1, 0);
    
    int total = 0;
    
    for (int i = 2; i <= N; i++) {
        if (!seen[minProductSum[i]]) {
            seen[minProductSum[i]] = true;
            total += minProductSum[i];
        }
    }
    
    cout << total << endl;
    
    return 0;
}