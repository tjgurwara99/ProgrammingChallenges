#include <bits/stdc++.h>
using namespace std;

int N, A, B;

int main() {
    
    cin >> N >> A >> B;
    A--; B--;
    
    int count = 0;
    while (A != B) {
        count++;
        A >>= 1;
        B >>= 1;
    }
    
    int final = 1;
    while (N > 2) {
        final++;
        N >>= 1;
    }
    
    if (count == final) {
        cout << "Final!" << endl;
    } else {
        cout << count << endl;
    }
    
    return 0;
}