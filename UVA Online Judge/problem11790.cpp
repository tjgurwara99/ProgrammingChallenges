#include <iostream>
using namespace std;

#define MAXN 200000
int N, sz[MAXN][2], lis[MAXN], lds[MAXN];
 
int main() {

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> sz[i][0]; // height
        for (int i = 0; i < N; i++) cin >> sz[i][1]; // width

        int mi = 0, md = 0;

        for (int i = N-1; i >= 0; i--) {
            lis[i] = lds[i] = sz[i][1];
            for (int j = i+1; j < N; j++) {
                if (sz[j][0] > sz[i][0]) lis[i] = max(lis[i], sz[i][1] + lis[j]);
                if (sz[j][0] < sz[i][0]) lds[i] = max(lds[i], sz[i][1] + lds[j]);
            }
            mi = max(mi, lis[i]);
            md = max(md, lds[i]);
        }

        if (mi >= md) printf("Case %d. Increasing (%d). Decreasing (%d).\n", t, mi, md);
        else          printf("Case %d. Decreasing (%d). Increasing (%d).\n", t, md, mi);
    }

    return 0;
}
