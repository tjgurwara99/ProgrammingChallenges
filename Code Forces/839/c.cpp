#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 200000

int N;
vector<int> graph[MAXN];

double expectedLength(int parent, int node) {

    double total = 0;
    int count = 0;

    for (int child : graph[node]) {
        if (child != parent) {
            total += expectedLength(node, child) + 1;
            count++;
        }
    }

    return count ? total / count : 0;
}

int main() {

    scanf("%d", &N);

    for (int i = 0; i < N-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    printf("%f\n", expectedLength(-1, 1));

    return 0;
}
