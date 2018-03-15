#include <bits/stdc++.h>
using namespace std;

#define MAXN (1 << 18)

vector<int> graph[MAXN];
bool seen[MAXN];

pair<int,int> colour(int node) {
    pair<int,int> res = make_pair(1, 0);
    seen[node] = true;
    
    for (int i = 0; i < (int)graph[node].size(); i++) {
        int c = graph[node][i];
        if (!seen[c]) {
            pair<int,int> r2 = colour(c);
            res.first += r2.second;
            res.second += r2.first;
        }
    }
    
    return res;
}

int main() {
    
    int N, a, b;
    
    scanf("%d", &N);
    while (scanf("%d %d", &a, &b), a != -1) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int total = 0;
    
    for (int i = 1; i <= N; i++) {
        if (seen[i]) continue;
        pair<int,int> res = colour(i);
        total += max(res.first, res.second);
    }
    
    printf("%d\n", total);
    
    return 0;
}