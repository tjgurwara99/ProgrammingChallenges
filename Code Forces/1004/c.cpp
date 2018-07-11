#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int N, A[200000];
int firstLeft[200000], firstRight[200000];
vector<int> lefts;

int main() {

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    for (int i = 1; i <= N; i++) {
        if (!firstLeft[A[i]]) {
            firstLeft[A[i]] = i;
            lefts.push_back(i);
        }
    }

    ll ans = 0;
    for (int i = N; i >= 0; i--) {
        if (!firstRight[A[i]]) {
            firstRight[A[i]] = i;
            ans += distance(lefts.begin(), upper_bound(lefts.begin(), lefts.end(), i-1));
        }
    }

    cout << ans << endl;

    return 0;
}