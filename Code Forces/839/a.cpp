#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

    int n, k, a = 0, b = 0;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a += x;

        int transfer = min(a, 8);
        b += transfer;
        a -= transfer;

        if (b >= k) {
            printf("%d\n", i+1);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}
