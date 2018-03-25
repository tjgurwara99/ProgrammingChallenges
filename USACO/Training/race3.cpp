/*
ID: basimkh1
PROG: race3
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 60
#define ll long long

int N;
vector<int> children[MAXN];
ll mask[MAXN];
bool visBefore[MAXN], visited[MAXN];

void splitFirst(int node, int split) {
    visBefore[node] = true;
    for (int c: children[node]) {
        if (c != split && !visBefore[c]) splitFirst(c, split);
    }
}

bool checkSplit(int node, int split) {
    visited[node] = true;
    for (int c: children[node]) {
        if (!visited[c] && (visBefore[c] || !checkSplit(c, split))) {
            return false;
        }
    }
    return true;
}

int main() {
    
    freopen("race3.in", "r", stdin);
    freopen("race3.out", "w", stdout);
   
    while (true) {
        int a;
        while (scanf("%d", &a), a >= 0) children[N].push_back(a);
        N++;
        if (a == -1) break;
    }
    N--;
    
    for (int i = 0; i < N; i++) mask[i] = (1LL << N)-1;
    
    vector<int> search;
    mask[0] = 1;
    search.push_back(0);
    
    while (!search.empty()) {
        int node = search.back();
        search.pop_back();
        
        for (int child: children[node]) {
            ll m = (mask[node] & mask[child]) | (1LL << child);
            if (mask[child] != m) {
                mask[child] = m;
                search.push_back(child);
            }
        }
    }
    
    vector<int> points, splits;
    
    for (int i = 1; i < N-1; i++) {
        if (mask[N-1] & (1LL << i)) {
            points.push_back(i);
            
            for (int i = 0; i < N; i++) visited[i] = visBefore[i] = false;
            
            splitFirst(0, i);
            if (checkSplit(i, i)) {
                splits.push_back(i);
            }
        }
    }
    
    printf("%d", (int)points.size());
    for (int p: points) printf(" %d", p);
    printf("\n");
    
    printf("%d", (int)splits.size());
    for (int s: splits) printf(" %d", s);
    printf("\n");
    
    return 0;
}