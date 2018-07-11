#include <iostream>
using namespace std;

int N, M, L[1001], R[1001];

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> L[i] >> R[i];

    for (int i = 0; i < N; i++) cout << "01"[i&1];
    cout << "\n";

    return 0;
}