#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define MAXN 250000

int N, L, U;
pair<int, int> A[MAXN];

int main() {
    
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> L >> U;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    
    sort(A, A+N);
    
    int start = 0, end = 1;
    ll sum = A[0].first;
    
    for (end = 1; end < N; end++) {
        if (sum > U) sum -= A[start++].first;
        if (sum >= L && sum <= U) break;
        sum += A[end].first;
    }
    if (sum > U) sum -= A[start++].first;
    
    if (sum >= L && sum <= U) {
        cout << (end - start) << endl;
        cout << A[start].second;
        for (start++; start < end; start++) cout << " " << A[start].second;
        cout << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}