#include <iostream>
using namespace std;

bool seen[1000];

int main() {

    int N, X, A[100];

    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        seen[A[i]] = true;
    }

    int count = 0; 
    for (int i = 0; i < X; i++) if (!seen[i]) count++;
    if (seen[X]) count++;

    cout << count << endl;

    return 0;
}
