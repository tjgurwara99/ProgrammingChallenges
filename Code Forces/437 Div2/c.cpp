#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 101000
#define ll long long

int main() {

    ll ans = 0, total = 0; 
    ll N, S;
    vector<pair<ll,ll>> c;

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        ll s, a, b;
        cin >> s >> a >> b;
        total += s;
        if (s) {
            c.push_back({a-b, s});
            ans += s * b;
        }
    }

    if (total % S) c.push_back({0, S - (total % S)});
    sort(c.begin(), c.end());

    ll csum = 0, crem = 0;

    for (auto& i : c) {
        ll a = i.first, s = i.second;
        if (crem + s >= S) {
            csum += a * (S - crem);
            ans += max(0LL, csum);
            s -= (S - crem);
            ans += (s / S) * max(S*a, 0LL);
            crem = s % S;
            csum = crem * a;
        } else {
            csum += s * a;
            crem += s;
        }
    }

    cout << ans << endl;

    return 0;
}
