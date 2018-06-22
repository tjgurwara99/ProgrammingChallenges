#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long

int N, K;
pair<int, pair<int, int> > knights[200000];
ll ans[200000];

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> knights[i].first;
    for (int i = 0; i < N; i++) cin >> knights[i].second.first;
    for (int i = 0; i < N; i++) knights[i].second.second = i;
    
    sort(knights, knights+N);
    
    multiset<int> maxPowers;
    ll maxTotal = 0;
    
    for (int i = 0; i < N; i++) {
        int coins = knights[i].second.first;
        int idx = knights[i].second.second;
        
        ans[idx] = coins + maxTotal;
        
        if (i < K) {
            maxPowers.insert(coins);
            maxTotal += coins;
        } else if (!maxPowers.empty() && *maxPowers.begin() < coins) {
            maxTotal -= *maxPowers.begin();
            maxPowers.erase(maxPowers.begin());
            maxPowers.insert(coins);
            maxTotal += coins;
        }
    }
    
    cout << ans[0];
    for (int i = 1; i < N; i++) cout << " " << ans[i];
    cout << endl;
    
    return 0;
}