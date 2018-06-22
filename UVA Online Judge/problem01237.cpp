#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXD 11000

int D;
char names[MAXD][30];
pair<int,int> db[MAXD];

int main() {
    
    int T;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d", &D);
        for (int i = 0; i < D; i++) scanf(" %s %d %d", names[i], &db[i].first, &db[i].second);
        
        int Q;
        scanf("%d", &Q);
        while (Q--) {
            int p, ans = -1;
            scanf("%d", &p);
            for (int i = 0; i < D; i++) {
                if (p >= db[i].first && p <= db[i].second) {
                    if (ans != -1) {
                        ans = -1;
                        break;
                    }
                    ans = i;
                }
            }
            if (ans == -1) printf("UNDETERMINED\n");
            else printf("%s\n", names[ans]);
        }
        
        if (T) printf("\n");
    }
    
    return 0;
}