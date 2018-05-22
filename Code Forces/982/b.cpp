#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

#define MAXN 210000

int N;
pair<int,int> W[MAXN];
set<pair<int, int> > empty, ones;

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &W[i].first);
        W[i].second = i+1;
    }
    
    empty = set<pair<int,int>>(W, W+N);
    
    for (int i = 0; i < 2*N; i++) {
        char c;
        scanf(" %c", &c);
        
        if (c == '0') {
            pair<int,int> a = *empty.begin();
            printf("%d", a.second);
            ones.insert(a);
            empty.erase(empty.begin());
        } else {
            pair<int,int> a = *ones.rbegin();
            printf("%d", a.second);
            ones.erase(--ones.end());
        }
        
        if (i < 2*N-1) printf(" ");
        else printf("\n");
    }
    
    
    return 0;
};