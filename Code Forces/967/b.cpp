#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int N, A, B, holes[MAXN], total;

inline bool valid(int toRemove) {
    double amount = (holes[0] * A * 1.0) / (total - toRemove);
    return (amount + 1e-6) > B;
}

int main() {
    
    cin >> N >> A >> B;
    
    for (int i = 0; i < N; i++) {
        cin >> holes[i];
        total += holes[i];
    }
    
    sort(holes+1, holes+N);
    
    int removeAmount = 0, ans = 0;
    while (!valid(removeAmount)) {
        removeAmount += holes[N-1-ans];
        ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}