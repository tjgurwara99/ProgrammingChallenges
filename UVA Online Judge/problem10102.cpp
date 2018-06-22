#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int M;
char grid[1000][1000];

int main() {
    
    while (scanf("%d", &M) != EOF) {
        
        vector<pair<int, int> > pos;
        
        for (int i = 0; i < M; i++) {
            scanf(" %s", grid[i]);
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '3') {
                    pos.push_back(make_pair(i, j));
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '1') {
                    int minDist = M*M;
                    for (auto& p: pos) {
                        int d = abs(p.first - i) + abs(p.second - j);
                        if (d < minDist) minDist = d;
                    }
                    ans = max(ans, minDist);
                }
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}