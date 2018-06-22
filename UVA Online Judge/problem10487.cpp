#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, a[1001], t = 0, p;

int main() {
    
    while (scanf("%d", &n), n) {
        printf("Case %d:\n", ++t);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &p);
            int closest = a[0] + a[1];
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    int c = a[i]+a[j];
                    if (abs(c - p) < abs(closest - p)) closest = c;
                }
            }
            printf("Closest sum to %d is %d.\n", p, closest);
        }
    }
    
    return 0;
}