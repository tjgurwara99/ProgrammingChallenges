/*
ID: basimkh1
PROG: cowxor
LANG: C++11
*/
#include <cstdio>
#define FOR(i,a,b) for (int i = a; i < b; i++)

int N, prefix[101000];
int positions[700000], nodeChild[700000][2], nodeCount = 1;

void trieInsert(int pos) {
    int node = 0;
    for (int i = 20; i >= 0; --i) {
        int child = (prefix[pos] & (1 << i)) ? 1 : 0;
        if (!nodeChild[node][child]) nodeChild[node][child] = nodeCount++;
        node = nodeChild[node][child];
    }
    positions[node] = pos;
}

int trieSearch(int pos) {
    int node = 0;
    for (int i = 20; i >= 0; --i) {
        int child = (prefix[pos] & (1 << i)) ? 0 : 1;
        node = nodeChild[node][child] ? nodeChild[node][child] : nodeChild[node][1-child];
    }
    return positions[node];
}

int main() {
    freopen("cowxor.in", "r", stdin);
    freopen("cowxor.out", "w", stdout);

    scanf("%d", &N);
    FOR(i,1,N+1) scanf("%d", &prefix[i]);
    FOR(i,1,N+1) prefix[i] ^= prefix[i-1];

    int bestAns = -1, bestStart, bestEnd;
    trieInsert(0);
    FOR(i,1,N+1) {
        int start = trieSearch(i);
        if ((prefix[i]^prefix[start]) > bestAns) {
            bestAns = prefix[i]^prefix[start];
            bestStart = start+1;
            bestEnd = i;
        }
        trieInsert(i);
    }
    printf("%d %d %d\n", bestAns, bestStart, bestEnd);
    return 0;
}