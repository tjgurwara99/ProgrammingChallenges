#include <cstdio>
#include <algorithm>
using namespace std;

int N, A[1001];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    sort(A, A+N);
    printf("%d\n", A[(N-1)/2]);
    return 0;
}