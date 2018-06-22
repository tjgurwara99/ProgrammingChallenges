#include <iostream>
using namespace std;

int N, M, A[100], B[100];
bool blocked[100], seen[100];

int main() {
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
        blocked[B[i]] = true;
    }
    bool first = true;
    for (int i = 0; i < N; i++) {
        if (blocked[A[i]]) {
            if (!first) cout << " ";
            first = false;
            cout << A[i];
        }
    }
    cout << endl;
     
    return 0;
}