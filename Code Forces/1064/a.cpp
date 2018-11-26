#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    int m = max(a, max(b, c));
    int s2 = a+b+c-m;
    
    printf("%d\n", (m < s2) ? 0 : (m - s2 + 1));
    
    return 0;
}