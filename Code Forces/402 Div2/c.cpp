#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 1000000

int N, K;
int A[MAXN], B[MAXN];
pair<int,int> C[MAXN];

int main() {
    
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i < N; i++) scanf("%d", &B[i]);
    
    for (int i = 0; i < N; i++) C[i] = make_pair(A[i]-B[i], i);
    sort(C, C+N);
    
    int total = 0;
    
    for (int i = 0; i < N; i++) {
        if (i < K) {
            total += A[C[i].second];
        } else {
            total += min(A[C[i].second], B[C[i].second]);
        }
    }
    
    printf("%d\n", total);
    
    return 0;
}
