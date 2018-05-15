#include <cstdio>

int N, K;
int groupOf[300];
int groupKey[300];
int numGroups;

int main() {
    
    scanf("%d %d", &N, &K);
    
    for (int t = 0; t < N; t++) {
        int p;
        scanf("%d", &p);
        
        int key;
        
        if (groupOf[p]) {
            key = groupKey[groupOf[p]];
        } else {
            
            bool found = false;
            
            for (int g = 1; g <= numGroups; g++) {
                int gend = groupKey[g]+K;
                if (groupKey[g] <= p && gend > p) {
                    found = true;
                    key = groupKey[g];
                    break;
                }
            }
            
            if (!found) {
                key = p - K + 1;
                if (key < 0) key = 0;
                numGroups++;
                while (groupOf[key]) ++key;
                groupKey[numGroups] = key;
                groupOf[key] = numGroups;
            }
            
            for (int i = key+1; i <= p; i++) groupOf[i] = groupOf[key];
        }
        
        if (t == 0) printf("%d", key);
        else printf(" %d", key);
    }
    printf("\n");
    
    return 0;
}