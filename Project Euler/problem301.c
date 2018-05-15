#include <stdio.h>
int main() {
    int ans = 0, i;
    for (i = 1; i <= 1<<30; i++) if (!(i ^ (i<<1) ^ (i+(i<<1)))) ++ans;
    printf("%d\n",ans);
    return 0;
}