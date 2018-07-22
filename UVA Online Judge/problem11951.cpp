#include <iostream>
using namespace std;

#define ll long long

int N, M;
ll K, grid[101][101], rowPrefix[101][101];

int main() {

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M >> K;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> grid[i][j];
                rowPrefix[i][j] = grid[i][j];
                if (j) rowPrefix[i][j] += rowPrefix[i][j-1];
            }
        }

        ll ans = 0, ansCost = 0;
        for (int a = 0; a < M; a++) {
            for (int b = a; b < M; b++) {
                int p = 0;
                ll total = 0;
                for (int q = 0; q < N; q++) {
                    total += rowPrefix[q][b] - (a ? rowPrefix[q][a-1] : 0);
                    while (total > K) {
                        total -= rowPrefix[p][b] - (a ? rowPrefix[p][a-1] : 0);
                        p++;
                    }
                    ll v = (b - a + 1) * (q - p + 1);
                    if (v > ans || (v == ans && total < ansCost)) {
                        ans = v;
                        ansCost = total;
                    }
                }
            }
        }
        cout << "Case #" << t << ": " << ans << " " << ansCost << endl;
    }

    return 0;
}