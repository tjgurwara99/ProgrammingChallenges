#include <iostream>
#include <algorithm>
using namespace std;

int N, M, A[20000], counts[2000001];

int main() {

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    while (cin >> N) {
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            counts[A[i]]++;
        }
        cin >> M;
        int a = -1;
        for (int i = 0; i < N; i++) {
            counts[A[i]]--;
            if (A[i] <= M && counts[M-A[i]]) a = max(a, min(A[i], M-A[i]));
        }
        cout << "Peter should buy books whose prices are " << a << " and " << M-a << ".\n\n";
    }

    return 0;
}