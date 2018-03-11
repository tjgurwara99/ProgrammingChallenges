#include <bits/stdc++.h>
using namespace std;

#define MAXN 66000
#define ll long long

inline int digitSum(ll x) {
    int sum = 0;
    for (; x; x /= 10) sum += x % 10;
    return sum;
}

inline int tick(ll x) { return 1-(digitSum(x)&1); }

ll countTicks(ll f, ll l) {
    ll total = 0;
    
    if (l-f < 100) {
        for (; f <= l; f++) total += tick(f);
        return total;
    }
    
    for (; f % 10; f++) total += tick(f);
    for (; l % 10; l--) total += tick(l);
    total += tick(l);
    total += (l - f) / 2;
    
    return total;
}

int main() {
    
    int N;
    scanf("%d", &N);
    
    vector<pair<ll,ll> > intervals;
    for (int i = 0; i < N; i++) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        intervals.push_back(make_pair(a, b));
    }
    
    sort(intervals.begin(), intervals.end());
    ll totalTime = 0, totalTicks = 0;
    
    for (int i = 0; i < N;) {
        ll start = intervals[i].first, end = intervals[i].second;
        for (; intervals[i].first <= end && i < N; i++) {
            end = intervals[i].second;
        }
        totalTime += end - start + 1;
        totalTicks += countTicks(start, end);
    }
    
    printf("%lld %lld\n", totalTime, totalTicks);
    
    return 0;
}