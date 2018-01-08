#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001
#define ARR(r, c) (r)*M+(c)

int N, M, K; 
int A[MAX], DP[MAX];
int columnDP[MAX];

int main() {

    scanf("%d %d", &N, &M);

    for (int r = 0; r < N; r++) {
        columnDP[r] = r;
        for (int c = 0; c < M; c++) {
            scanf("%d", &A[ARR(r,c)]);

            if (r) {
                if (A[ARR(r,c)] < A[ARR(r-1,c)]) {
                    DP[ARR(r,c)] = r;
                } else {
                    DP[ARR(r,c)] = DP[ARR(r-1,c)];
                }
            }
            columnDP[r] = min(columnDP[r], DP[ARR(r,c)]);
        }
    }

    scanf("%d", &K);

    for (int i = 0; i < K; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--; r--;

        if (columnDP[r] <= l) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
