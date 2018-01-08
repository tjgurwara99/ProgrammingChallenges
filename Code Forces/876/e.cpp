#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 110000

int N, M;
vector<int> A[MAX], capitals, before[MAX];
bool isCapital[MAX], impossible;

void makeBefore(int a, int b) {
    if (a < b) {
        if (isCapital[b] && !isCapital[a]) {
            capitals.push_back(a);
            isCapital[a] = true;
            for (int c: before[a]) makeBefore(c, a);
        }
    } else if (a > b) {
        if (isCapital[b]) {
            impossible = true;
            return;
        }
        if (!isCapital[a]) {
            capitals.push_back(a);
            isCapital[a] = true;
            for (int c: before[a]) makeBefore(c, a);
        }
    }
}

int main() {
    
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        int l;
        scanf("%d", &l);
        A[i].resize(l);
        for (int j = 0; j < l; j++) scanf("%d", &A[i][j]);
    }
    
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < (int)A[i].size(); j++) {
            if (j == (int)A[i+1].size()) {
                impossible = true;
                break;
            }
            
            if (A[i][j] != A[i+1][j]) {
                before[A[i+1][j]].push_back(A[i][j]);
                break;
            }
        }
        
        if (impossible) break;
    }
    
    for (int d = 1; d <= M; d++) {
        for (int c : before[d]) {
            makeBefore(c, d);
            if (impossible) break;
        }
        if (impossible) break;
    }
    
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < (int)A[i].size(); j++) {
            if (j == A[i+1].size()) {
                impossible = true;
                break;
            }
            
            int p = A[i][j], q = A[i+1][j];
            if (isCapital[p]) p -= MAX;
            if (isCapital[q]) q -= MAX;
            
            if (p > q) {
                impossible = true;
                break;
            } else if (p < q) {
                break;
            }
        }
        if (impossible) break;
    }
    
    if (impossible) printf("No\n");
    else {
        printf("Yes\n%d\n", (int)capitals.size());
        for (int c : capitals) printf("%d ", c);
    }
    
    return 0;
}