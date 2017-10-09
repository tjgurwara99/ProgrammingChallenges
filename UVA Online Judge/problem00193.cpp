#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, colour[101], maxBlack, ans[101]; 
vector<int> graph[101];

void search(int idx, int numBlack) {
    if (numBlack+N-idx+1 <= maxBlack) return;
    if (idx == N+1) {
        maxBlack = numBlack;
        for (int i = 1; i <= N; i++) ans[i] = colour[i];
        return;
    }

    bool canBlack = true;
    for (int p : graph[idx]) if (colour[p]) { canBlack = false; break; }

    if (canBlack) {
        colour[idx] = 1;
        search(idx+1, numBlack+1);
        colour[idx] = 0;
    }
    search(idx+1, numBlack);
}

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &N, &K);
        for (int i = 1; i <= N; i++) graph[i].clear();

        for (int i = 0; i < K; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        maxBlack = 0;
        search(1, 0);
        printf("%d\n", maxBlack);
        for (int i = 1; i <= N && maxBlack >= 0; i++) {
            if (ans[i] == 1) {
                printf((maxBlack != 1) ? "%d " : "%d\n", i);
                maxBlack--;
            }
        }
    }

    return 0;
}
