#include <bits/stdc++.h>
using namespace std;

#define MAXS 100

int S;
vector<int> children[MAXS];
int boss[MAXS];
bool cleared[MAXS];

bool advance(int node) {
    
    for (int i = 0; i < (int)children[node].size(); i++) {
        int c = children[node][i];
        
        if (!cleared[c]) {
            cleared[c] = true;
            return true;
        } else {
            if (advance(c)) {
                return true;
            } else {
                cleared[c] = false;
            }
        }
    }
    
    return false;
}

int main() {
    
    int H;
    scanf("%d %d", &S, &H);
    
    for (int i = 2; i <= S; i++) {
        cin >> boss[i];
        children[boss[i]].push_back(i);
    }
    
    for (int i = 0; i < H; i++) {
        printf("1");
        for (int j = 2; j <= S; j++) if (cleared[j]) printf(" %d", j);
        printf("\n");
        advance(1);
    }
    
    return 0;
}