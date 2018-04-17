#include <cstdio>
using namespace std;

#define MAXK 20000

int K, A[MAXK], indexFill[MAXK];

struct node { int prev, next; };
node NODES[MAXK];
 
int main() {
    
    scanf("%d", &K);
    for (int i = 1; i <= K; i++) {
        scanf("%d", &A[i]);
        A[i]--;
        
        NODES[i].prev = i-1;
        NODES[i].next = i+1;
    }
    
    NODES[1].prev = K;
    NODES[K].next = 1;

    int currentPos = 1;
    for (int i = 1; i <= K; i++) {
        int steps = A[i] % (K-i+1);
        while (steps--) currentPos = NODES[currentPos].next;
        indexFill[currentPos] = i;
        
        NODES[NODES[currentPos].prev].next = NODES[currentPos].next;
        NODES[NODES[currentPos].next].prev = NODES[currentPos].prev;
        currentPos = NODES[currentPos].next;
    }
    
    for (int i = 1; i <= K; i++)  printf("%d\n", indexFill[i]);
    
    return 0;
}