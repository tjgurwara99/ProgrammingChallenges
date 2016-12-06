#include <cstdio>
using namespace std;

int main() {
    
    char A, B;
    int n, a, b, c, i;
    
    scanf(" %c %c %d", &A, &B, &n);
    
    a = A-'A'+1;
    b = B-'A'+1;
    
    for (i = 1; i < n; i++) {
        c = a + b;
        if (c > 26) c -= 26;
        a = b;
        b = c;
    }
    
    printf("%c\n", (char)((a-1)+'A'));
    
    return 0;
}