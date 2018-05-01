#include <iostream>
#include <set>
using namespace std;

#define MAXN 100000000
#define ll long long

set<int> seen;

inline bool isPalindrome(ll n) {
    ll rev = 0;
    for (ll a = n; a; a /= 10) rev = rev*10 + a%10;
    return rev == n;
}

int main() {
    ll ans = 0;
    for (ll i = 1; i*i <= MAXN; i++) {
        ll total = i*i;
        for (ll j = i+1; j*j < MAXN; j++) {
            total += j*j;
            if (total > MAXN) break;
            if (isPalindrome(total) && seen.count(total) == 0) {
                seen.insert(total);
                ans += total;
            }
        }
    }
    cout << ans << endl;
    return 0;
}