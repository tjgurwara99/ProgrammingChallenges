#include <bits/stdc++.h>
using namespace std;

int N, A[50000];

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    
    set<int> lis;
    for (int i = 0; i < N; i++) {
        set<int>::iterator next = lis.insert(A[i]).first;
        if (++next != lis.end()) lis.erase(next);
    }
    cout << (N - (int)lis.size()) << " ";
    
    int minElem = A[N-1], count = 0;
    for (int i = N-2; i >= 0; --i) {
        if (A[i] > minElem) count++;
        else minElem = A[i];
    }
    cout << count << endl;
    
    return 0;
}