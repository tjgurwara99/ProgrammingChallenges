/*
ID: basimkh1
PROG: hidden
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)

int L;
char S[200000];

int main() {
    
    freopen("hidden.in", "r", stdin); freopen("hidden.out", "w", stdout);
    
    scanf("%d", &L);
    for (int pos = 0; pos < L; pos += strlen(S+pos)) scanf(" %s", S+pos);
    
    vector<int> startPositions, temp;
    FOR(i,0,L) startPositions.push_back(i);
    
    FOR(l,1,L+1) {
        char bestNext = 127;
        temp.clear();
        int lastPos = -2*L;
        for (int pos: startPositions) {
            if (pos < lastPos + l) continue;
            int endPos = (pos+l-1) % L;
            if (S[endPos] < bestNext) {
                temp.clear();
                bestNext = S[endPos];
            }
            if (S[endPos] == bestNext) {
                temp.push_back(pos);
                lastPos = pos;
            }
        }
        swap(startPositions, temp);
    }
    
    printf("%d\n", startPositions[0]);
    
    return 0;
}