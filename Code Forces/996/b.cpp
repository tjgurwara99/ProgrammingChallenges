#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N, A, location = -1, locationA;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> A;
        if ((A % N) != i) {
            int diff = i - (A % N);
            if (diff < 0) diff += N;
            A += diff;
        }
        if (location == -1 || A < locationA) {
            location = i;
            locationA = A;
        }
    }
    cout << location+1 << endl;
    
    return 0;
}