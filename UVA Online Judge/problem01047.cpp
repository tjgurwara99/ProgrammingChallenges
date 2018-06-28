#include <cstdio>
#include <vector>
using namespace std;

int N, K, M, P[20];
vector<pair<int, vector<int> > > overlaps;
bool used[20];

int bestSolution;
bool bestValues[20];

void solve(int start, int left) {
    
    if (!left) {
        int sol = 0;
        for (int i = 0; i < N; i++) {
            if (used[i]) sol += P[i];
        }
        for (int i = 0; i < M; i++) {
            int cnt = 0;
            for (int v: overlaps[i].second) {
                if (used[v]) cnt++;
            }
            if (cnt) sol -= (cnt - 1) * overlaps[i].first;
        }
        
        if (sol > bestSolution) {
            bestSolution = sol;
            for (int i = 0; i < N; i++) bestValues[i] = used[i];
        }
        return;
    }
    
    for (int i = start; i < N; i++) {
        used[i] = true;
        solve(i+1, left-1);
        used[i] = false;
    }
}

int main() {
    
    int t = 0;
    while (scanf("%d %d", &N, &K), N) {
        printf("Case Number  %d\n", ++t);
        for (int i = 0; i < N; i++) scanf("%d", &P[i]);
        scanf("%d", &M);
        overlaps.clear();
        for (int i = 0; i < M; i++) {
            int t, p;
            scanf("%d", &t);
            vector<int> towers(t);
            for (int j = 0; j < t; j++) {
                scanf("%d", &towers[j]);
                towers[j]--;
            }
            scanf("%d", &p);
            overlaps.push_back(make_pair(p, towers));
        }
        
        bestSolution = 0;
        solve(0, K);
        printf("Number of Customers: %d\n", bestSolution);
        printf("Locations recommended:");
        for (int i = 0; i < N; i++) if (bestValues[i]) printf(" %d", i+1);
        printf("\n\n");
    }
    
    return 0;
}