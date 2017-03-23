#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 1000002
int N;
vector<int> graph[MAXN];
bool inSecond[MAXN];

inline bool validSpy(int p) {
    int count = 0;
    for (int i = 0; i < (int)graph[p].size(); i++) {
        if (inSecond[p] == inSecond[graph[p][i]]) {
            if (++count == 2) return false;
        }
    }
    return true;
}

int main() {

    scanf("%d", &N);

    int a, b;
    while (scanf("%d %d", &a, &b), a != -1) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> spies;
    for (int i = 1; i <= N; i++) spies.push(i);

    int firstCount = N;

    while (!spies.empty()) {
        int p = spies.front();
        spies.pop();
        if (!validSpy(p)) {
            inSecond[p] = !inSecond[p];
            if (inSecond[p]) firstCount--;
            else firstCount++;

            for (int i = 0; i < (int)graph[p].size(); i++) {
                if (!validSpy(graph[p][i])) spies.push(graph[p][i]);
            }
        }
    }

    printf("%d\n", firstCount);
    for (int i = 1; i <= N; i++) {
        if (!inSecond[i]) printf("%d\n", i);
    }

    return 0;
}
