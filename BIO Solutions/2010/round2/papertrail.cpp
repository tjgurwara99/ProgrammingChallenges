#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
using namespace std;

#define MAXHOUSES 256

int numHouses, startPos;
int P[MAXHOUSES], N[MAXHOUSES];
int nPrefixSum[MAXHOUSES];

inline int costToHouse(int pos, int numPapers, int houseIdx) {
    return abs(pos - P[houseIdx]) * numPapers;
}

inline int getNumPapers(int leftMostVisit, int rightMostVisit) {
    int numDelivered = nPrefixSum[rightMostVisit] - nPrefixSum[leftMostVisit] + N[leftMostVisit];
    return nPrefixSum[numHouses-1]-numDelivered;    
}

int minimumEffort(int pos, int leftMostVist, int rightMostVisit) {
    int leftHouse = leftMostVist-1, rightHouse = rightMostVisit+1;
    int numPapers = getNumPapers(leftMostVist, rightMostVisit);
    
    if (numPapers == 0) {
        assert(leftHouse == -1);
        assert(rightHouse == numHouses);
        return 0;
    }
    
    if (rightHouse == numHouses) {
        return costToHouse(pos, numPapers, leftHouse)
             + minimumEffort(P[leftHouse], leftHouse, rightMostVisit);
        
    } else if (leftHouse == -1) {
        return costToHouse(pos, numPapers, rightHouse)
             + minimumEffort(P[rightHouse], leftMostVist, rightHouse);
        
    }
    
    int lCost = costToHouse(pos, numPapers, leftHouse)
         + minimumEffort(P[leftHouse], leftHouse, rightMostVisit);
    int rCost = costToHouse(pos, numPapers, rightHouse)
         + minimumEffort(P[rightHouse], leftMostVist, rightHouse);
    
    return min(lCost, rCost);
}

int main() {
    
    scanf("%d %d", &numHouses, &startPos);
    int prevHouse = -1, nextHouse = numHouses;
    
    for (int i = 0; i < numHouses; i++) {
        scanf("%d %d", &P[i], &N[i]);
        nPrefixSum[i] = N[i];
        if (i > 0) nPrefixSum[i] += N[i-1];
    
        if (P[i] > startPos) {
            nextHouse = i;
            break;
        } else {
            prevHouse = i;
        }
    }
    
    printf("%d\n", minimumEffort(startPos, nextHouse, prevHouse));
    
    return 0;
}