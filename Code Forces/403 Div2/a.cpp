#include <cstdio>
#include <algorithm>
using namespace std;

int A[200000];

int main() {

    int N;
    scanf("%d", &N);

    int maxCount = 0;
    int count = 0;

    for (int i = 0; i < 2*N; i++) {
        int x;
        scanf("%d", &x);

        if (A[x]) {
            A[x] = 0;
            count--;
        } else {
            A[x] = 1;
            count++;
            maxCount = max(maxCount, count);
        }
    }

    printf("%d\n", maxCount);
    return 0;
}
