#include <bits/stdc++.h>
using namespace std;

int N, A[50], ans;
bool used[50];
pair<int,int> nodes[50];

void bruteForce(int spyCount, int startPos) {
    
    if (spyCount == 0) {
        ++ans;
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (used[i]) continue;
        
        int pos = startPos;
        int steps = A[i] % spyCount;
        while (steps--) pos = nodes[pos].second;
        
        if (pos == i) {
            used[i] = true;
            nodes[nodes[i].first].second = nodes[i].second;
            nodes[nodes[i].second].first = nodes[i].first;
            
            bruteForce(spyCount-1, nodes[i].second);
            
            nodes[nodes[i].first].second = i;
            nodes[nodes[i].second].first = i;
            used[i] = false;
        }
    }
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        A[i]--;
        nodes[i].first = i-1;
        nodes[i].second = i+1;
    }
    nodes[1].first = N;
    nodes[N].second = 1;
    
    bruteForce(N, 1);
    printf("%d\n", ans);
    
    return 0;
}