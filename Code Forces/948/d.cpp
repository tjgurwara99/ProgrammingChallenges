#include <bits/stdc++.h>
using namespace std;

#define MAXN 905000
int N, A[MAXN], P[MAXN];

int trieCount = 1;
int children[MAXN*10][2], childCount[MAXN*10], value[MAXN*10];

void addTrie(int node, int n, int b) {
    childCount[node]++;
    if (b < 0) {
        value[node] = n;
        return;
    }
    
    int nextChild = (n & (1 << b)) ? 1 : 0;
    if (children[node][nextChild] == 0) {
        children[node][nextChild] = trieCount++;
    }
    addTrie(children[node][nextChild], n, b-1);
}

void removeTrie(int node, int n, int b) {
    childCount[node]--;
    if (b < 0) return;
    
    int nextChild = (n & (1 << b)) ? 1 : 0;
    removeTrie(children[node][nextChild], n, b-1);
}

int findSimilar(int node, int n, int b) {
    if (b < 0) return value[node];
    
    int nextChild = (n & (1 << b)) ? 1 : 0;
    if (!children[node][nextChild] || !childCount[children[node][nextChild]]) {
        nextChild = 1-nextChild;
    }
    
    return findSimilar(children[node][nextChild], n, b-1);
}

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
        addTrie(0, P[i], 29);
    }

    for (int i = 0; i < N; i++) {
        int p = findSimilar(0, A[i], 29);
        cout << (A[i] ^ p) << " ";
        removeTrie(0, p, 29);
    }
    cout << endl;
    
    return 0;
}