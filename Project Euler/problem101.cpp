#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll factorial(int n) {
    ll f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}

ll power(int a, int b) {
    ll r = 1;
    for (int i = 0; i < b; i++) r *= a;
    return r;
}

vector<int> optimumPoly(const vector<ll>& a) {
    int n = (int)a.size();
    if (n == 1) {
        return { (int)a[0] };
    }
    
    vector<ll> diff(a);
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            diff[j] = diff[j+1] - diff[j];
        }
    }
    
    int d = (int)(diff[0] / factorial(n-1));
    vector<ll> newVec(n-1);
    for (int i = 0; i < n-1; i++) {
        newVec[i] = a[i] - d * power(i+1, n-1);
    }
    
    vector<int> res = optimumPoly(newVec);
    res.push_back(d);
    return res;
}

ll nthTerm(const vector<int>& poly, int n) {
    ll total = 0, p = 1;
    for (int a: poly) {
        total += a * p;
        p *= n;
    }
    return total;
}

ll fit(const vector<ll>& terms, const vector<int>& approx) {
    for (int i = 1; i < (int)terms.size(); i++) {
        ll a = nthTerm(approx, i);
        if (a != terms[i-1]) {
            return a;
        }
    }
    return -1;
}

ll solve(const vector<int>& poly) {
    int d = (int)poly.size()-1;
    
    vector<ll> terms;
    for (int i = 0; i <= 2*d; i++) terms.push_back(nthTerm(poly, i+1));
    
    ll ans = 0;
    
    for (int order = 0; order < d; order++) {
        vector<ll> a(order+1);
        for (int i = 0; i <= order; i++) a[i] = terms[i];
        
        vector<int> p2 = optimumPoly(a);
        ans += fit(terms, p2);
    }
    
    return ans;
}

int main() {
    
    vector<int> poly(11);
    for (int i = 0; i < 11; i++) poly[i] = power(-1, i);
    cout << solve(poly) << endl;
    
    return 0;
}