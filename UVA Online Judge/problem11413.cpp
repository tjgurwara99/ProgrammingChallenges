#include <iostream>
using namespace std;

int N, M, A[2000];

inline bool possible(int maxSize) {
    int cnt = 0, acc = 0;
    for (int i = 0; i < N && cnt <= M; i++) {
        if (A[i] > maxSize) return false;
        acc += A[i];
        if (acc > maxSize) {
            acc = 0;
            cnt++;
            i--;
        }
    }
    if (acc) cnt++;
    return cnt <= M;
}

int main() {

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    while (cin >> N >> M) {
        int l = 0, h = 0;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            h += A[i];
        }
        while ((h-l) > 1) {
            int m = (l + h) / 2;
            if (possible(m)) h = m;
            else l = m;
        }
        printf("%d\n", h);
    }

    return 0;
}