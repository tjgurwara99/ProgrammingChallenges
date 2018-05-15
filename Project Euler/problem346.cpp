#include <cstdio>
#include <set>
using namespace std;

#define MAXN ((long)1e12)

int main() {
    
    set<long> ans;
    ans.insert(1);
    for (long b = 2; b*b+b+1 < MAXN; b++) {
        for (long c = b*b+b+1; c < MAXN; c = c*b+1) ans.insert(c);
    }
    
    long total = 0;
    for (const long& i: ans) total += i;
    
    printf("%ld\n", total);
    
    return 0;
}