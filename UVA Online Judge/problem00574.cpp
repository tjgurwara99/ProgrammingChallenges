#include <cstdio>
#include <vector>
using namespace std;

int N, M, A[15];
bool found;
vector<int> current;

void solve(int pos) {
    if (pos == M) {
        int t = 0;
        for (int x: current) t += x;
        if (t == N) {
            found = true;
            printf("%d", current[0]);
            for (int i = 1; i < (int)current.size(); i++) printf("+%d", current[i]);
            printf("\n");
        }
        return;
    }
    
    int nextPos = pos;
    while (nextPos < M && A[nextPos] == A[pos]) nextPos++;
    
    for (int i = 0; i < nextPos-pos; i++) current.push_back(A[pos]);
    for (int i = 0; i < nextPos-pos; i++) {
        solve(nextPos);
        current.pop_back();
    }
    solve(nextPos);
}

int main() {
    
    while (scanf("%d %d", &N, &M), N) {
        for (int i = 0; i < M; i++) scanf("%d", &A[i]);
        found = false;
        printf("Sums of %d:\n", N);
        solve(0);
        if (!found) printf("NONE\n");
    }
    
    return 0;
}