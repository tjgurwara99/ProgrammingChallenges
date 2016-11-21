/* Correct answer 9ms */
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long
#define MAX 80

int A[MAX][MAX];
ll dist[MAX][MAX];

vector<pair<int, int> > directions = {
    make_pair(-1, 0), // Up
    make_pair(1, 0),  // Down
    make_pair(0, -1), // Left
    make_pair(0, 1)   // Right
};

priority_queue<pair<ll, pair<int, int> > > searchNodes;

void loadData() {
    FILE* f = fopen("p083_matrix.txt", "r");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) fscanf(f, "%d,", &A[i][j]);
    }
    fclose(f);
}

int main() {
    
    loadData();
    
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dist[i][j] = INFINITY;
        }
    }
    dist[0][0] = A[0][0];
    searchNodes.push(make_pair(0, make_pair(0, 0)));
    
    while (!searchNodes.empty()) {
        pair<ll, pair<int, int> > newNode = searchNodes.top();
        searchNodes.pop();
        
        int r = newNode.second.first;
        int c = newNode.second.second;
        ll d = dist[r][c];
        
        for (pair<int, int>& dir: directions) {
            int cy = r + dir.first;
            int cx = c + dir.second;
            
            if (cx >= MAX || cx < 0 || cy >= MAX || cy < 0) continue;
            
            if (dist[cy][cx] > d + A[cy][cx]) {
                dist[cy][cx] = d + A[cy][cx];
                searchNodes.push(make_pair(-dist[cy][cx], make_pair(cy, cx)));
            }
        }
    }
    
    printf("%lld\n", dist[MAX-1][MAX-1]);
    
    return 0;
}