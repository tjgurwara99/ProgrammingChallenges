#include <cstdio>
#include <cstring>

struct node {
    int idx;
    int children[26];
};

node NODES[10000];
int nodeCount = 1;
int townCount = 0;

int addWord(char *word) {
    int currentNode = 0;
    for (int i = 0; i < 5; i++) {
        int childIdx = word[i]-'A';
        if (NODES[currentNode].children[childIdx] == 0) {
            NODES[currentNode].children[childIdx] = nodeCount++;
        }
        currentNode = NODES[currentNode].children[childIdx];
    }
    if (NODES[currentNode].idx == 0) NODES[currentNode].idx = ++townCount;
    return NODES[currentNode].idx;
}

int sz[5000], parent[5000];

int root(int a) {
    return a == parent[a] ? a : (parent[a] = root(parent[a]));
}

void connect(int a, int b) {
    int p = root(a), q = root(b);
    if (p == q) return;
    
    if (sz[p] > sz[q]) {
        sz[p] += sz[q];
        parent[q] = p;
    } else {
        sz[q] += sz[p];
        parent[p] = q;
    }
}

int main() {
    
    for (int i = 0; i < 5000; i++) {
        sz[i] = 1;
        parent[i] = i;
        NODES[i].idx = 0;
        for (int j = 0; j < 26; j++) NODES[i].children[j] = 0;
    }
    
    char first[10], second[10];
    
    while (scanf(" %s", first), strcmp(first, "XXXXX")) {
        scanf(" %s", second);
        connect(addWord(first), addWord(second));
    }
    
    int setCount = 0;
    
    for (int i = 1; i <= townCount; i++) {
        if (parent[i] == i) setCount++;
    }
    
    printf("%d %d\n", townCount, setCount);
    
    return 0;
}