#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 100000

int n, n1, n2;
int a[MAXN];

int main() {

    scanf("%d %d %d", &n, &n1, &n2);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a+n);

    if (n1 < n2) {
        int temp = n2;
        n2 = n1;
        n1 = temp;
    }

    double s1 = 0, s2 = 0;

    for (int i = n-n1-n2; i < n-n2; i++) s1 += a[i];
    for (int i = n-n2; i < n; i++) s2 += a[i];

    printf("%.6f\n", s1/n1 + s2/n2);

    return 0;
}
