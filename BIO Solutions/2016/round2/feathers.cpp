#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long

int N, A[41];
pair<int, int> indexedNums[41];
bool inFirst[41];
ll nchoosek[41][41];

void printAnswer(int m, ll idx, int minIdx) {
    if (m == 0) return;
    
    for (int i = 0; i < N; i++) {
        int newIdx = indexedNums[i].second;
        
        if (newIdx >= minIdx && newIdx <= N-m) {
            ll amount = nchoosek[N-newIdx-1][m-1];
            if (amount > idx) {
                printf("%d ", indexedNums[i].first);
                inFirst[newIdx] = true;
                printAnswer(m-1, idx, newIdx+1);
                return;
            }
            idx -= amount;
        }
    }
}

int main() {
    
    int M;
    ll I;
    scanf("%d %d %lld", &N, &M, &I);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        indexedNums[i].first = A[i];
        indexedNums[i].second = i;
    }
    
    sort(indexedNums, indexedNums+N);
    
    for (int i = 0; i <= N; i++)  nchoosek[i][0] = nchoosek[i][i] = 1;
    for (int n = 1; n <= N; n++) {
        for (int k = 1; k < n; k++) {
            nchoosek[n][k] = nchoosek[n-1][k-1] + nchoosek[n-1][k];
        }
    }
    
    printAnswer(M, I-1, 0);
    
    for (int i = 0; i < N; i++) {
        if (!inFirst[i]) printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}