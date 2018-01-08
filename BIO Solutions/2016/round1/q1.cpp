#include <cstdio>

int main() {
    int l = 1, m = 0, r = 0, s = 1, a = 1, b = 1;
    char S[20];
    scanf("%s", S);
    
    for (int i = 0; S[i]; i++) {
        if (S[i] == 'L') {
            l = a;
            m = b;
        } else {
            r = a;
            s = b;
        }
        a = l+r;
        b = m+s;
    }
    
    printf("%d / %d\n", a, b);
    return 0;
}