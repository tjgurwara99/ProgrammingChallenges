#include <cstdio>
using namespace std;

#define MAXK 20000

int K, A[MAXK];
int indexFill[MAXK];

struct node {
    int idx, prev, next;
};

node NODES[MAXK];
 
int main() {
    
    scanf("%d", &K);
    for (int i = 1; i <= K; i++) {
        scanf("%d", &A[i]);
        NODES[i].idx = i;
        NODES[i].prev = i-1;
        NODES[i].next = i+1;
    }
    
    NODES[1].prev = K;
    NODES[K].next = 1;

    int currentPos = 1;
    
    for (int i = 1; i <= K; i++) {
        
        for (int j = 1; j < A[i]; j++) {
            currentPos = NODES[currentPos].next;
        }
        
        indexFill[NODES[currentPos].idx] = i;
        
        // Remove this node
        NODES[NODES[currentPos].prev].next = NODES[currentPos].next;
        NODES[NODES[currentPos].next].prev = NODES[currentPos].prev;
        currentPos = NODES[currentPos].next;
    }
    
    for (int i = 1; i <= K; i++)  printf("%d\n", indexFill[i]);
    
    return 0;
}