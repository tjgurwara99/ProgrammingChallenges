#include <cstdio>
#define MAXN 2600

int N, excluded[MAXN];

int main() {
    
    scanf("%d", &N);
    
    int a, b;
    while(scanf("%d %d", &a, &b), a != -1) {
        if (!excluded[a] && !excluded[b]) {
            excluded[a] = excluded[b] = true;
        }
    }
    
    int numsToFind = N/3;
    for (int i = 1; i <= N && numsToFind; i++) {
        if (!excluded[i]) {
            printf("%d\n", i);
            numsToFind--;
        }
    }
    
    return 0;
}