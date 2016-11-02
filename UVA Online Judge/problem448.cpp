#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXS 21000

int main () {
    
    int b, s;
    scanf("%d", &b);
    
    for (int r = 1; r <= b; r++) {
        scanf("%d", &s);
        
        int currentSum = 0, maxSum = -1;
        int currentStart = 1, maxStartIndex = -1, maxEndIndex = -1; 
        
        for (int i = 1; i <= s-1; i++) {
            int N;
            scanf("%d", &N);
            currentSum += N;
            
            if (currentSum < 0) {
                currentSum = 0;
                currentStart = i+1;
            }
            
            if (currentSum > maxSum || (currentSum == maxSum && (i - currentStart > maxEndIndex - maxStartIndex))) {
                maxSum = currentSum;
                maxStartIndex = currentStart;
                maxEndIndex = i+1;
            }
        }
        
        if (maxSum <= 0)  printf("Route %d has no nice parts\n", r);
        else              printf("The nicest part of route %d is between stops %d and %d\n", r, maxStartIndex, maxEndIndex);
    }
    
    return 0;
}