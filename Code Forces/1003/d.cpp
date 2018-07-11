#include <cstdio>
#include <algorithm>
using namespace std;

int counts[32];

inline int log2(int a) {
    int t = 0;
    for (; a; a >>= 1) t++;
    return t-1;
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    while (N--) {
        int a;
        scanf("%d", &a);
        counts[log2(a)]++;
    }
    while (Q--) {
        int b, ans = 0;
        scanf("%d", &b);
        for (int i = 30; i >= 0; i--) {
            int c = min(b>>i, counts[i]);
            ans += c;
            b -= (1<<i) * c;
        }
        printf("%d\n", b>0 ? -1 : ans);
    }
    return 0;
}