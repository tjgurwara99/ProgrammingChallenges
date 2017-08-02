#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 100005

int N, A[2];
vector<pair<int,int>> beauty[2];
vector<pair<int,int>> price[2];

int maximiseBeauty(int c) {
    if (beauty[c].size() < 2) return 0;

    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < (int)beauty[c].size(); i++) {
        pq.push(-beauty[c].first, beauty[c].second);
    }

    int maxBeauty = 0;
    int topPointer = (int)price[c].size() -1;
    for (int i = 0; i < (int)price[c].size(); i++) {
        while (topPointer > i && price[c][topPointer].second + price[c][i].second > A[c]) {
            topPointer--;
        }
    }
    return maxBeauty;
}

int main() {

    scanf("%d %d %d", &N, &A[0], &A[1]);

    for (int i = 0; i < N; i++) {
        int b, p;
        char t;
        scanf("%d %d %c", &b, &p, &t);
        int c = t == 'C' ? 0 : 1;
        if (p >= A[c]) continue;
        beauty[c].push_back(make_pair(b, p));
        price[c].push_back(make_pair(p, b));
    }

    sort(beauty[0].begin(), beauty[0].end());
    sort(beauty[1].begin(), beauty[1].end());
    sort(price[0].begin(), price[0].end());
    sort(price[1].begin(), price[1].end());

    int maxBeauty = 0;

    // one from coin, one from diamond
    if (!beauty[0].empty() && !beauty[1].empty()) {
        maxBeauty = beauty[0][beauty[0].size()-1].first + beauty[1][beauty[1].size()-1].first;
    }

    // two from coins or diamond
    maxBeauty = max(maxBeauty, maximiseBeauty(0));
    maxBeauty = max(maxBeauty, maximiseBeauty(1));

    printf("%d\n", maxBeauty);

    return 0;
}
