#include <cstdio>

int counts[101];

int main() {

    int ans = 0, n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (++counts[a] > counts[ans]) ans = a;
    }

    printf("%d\n", counts[ans]);

    return 0;
}