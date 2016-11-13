#include <cstdio>
#include <cmath>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

#define ll long long

inline bool isPerfectSquare(ll n) {
    int h = n & 0xF;  // h is the last hex "digit"
    if (h > 9) return false;
    // Use lazy evaluation to jump out of the if statement as soon as possible
    if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8) {
        ll t = (ll)floor(sqrt((double)n)+0.5);
        return t*t == n;
    }
    return false;
}

class ContinuedFraction {
public:
    pair<ll, ll> num; //First = Square root, Second = Integer part
    pair<ll, ll> den;
    
    ContinuedFraction () {}
    ContinuedFraction (ll nS, ll nI, ll dS, ll dI) : num(make_pair(nS, nI)), den(make_pair(dS, dI)) {}
    
    ContinuedFraction reciprocal() {
        return ContinuedFraction(den.first, den.second, num.first, num.second);
    }
    
    ContinuedFraction rationaliseDenominator() {
        
        ll d = den.first - (den.second * den.second);
        
        //Make some assumptions (for this calculation only)
        assert(num.first == 1);
        assert(den.second <= 0);
        assert(d % num.second == 0);
        
        return ContinuedFraction(den.first, -(den.second), 1, d / num.second);
    }
    
    string toString() const {
        return "(√" + to_string(num.first) + " + " + to_string(num.second) + ") / (√" + to_string(den.first) + " + " + to_string(den.second) + ")";
    }
    
    bool operator==(const ContinuedFraction& other) const {
        return other.num == num && other.den == den;
    }
    
    bool operator!=(const ContinuedFraction& other) const {
        return !(*this == other);
    }
};

class Rational {

    ll n, d;

    ll gcd(ll a, ll b) const {
        ll c;
        while (b) {
            c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
    
public:

    Rational(ll n, ll d) { 
        assert(d != 0);

        this->n = n; this->d = d;

        if (n != 0) {
            ll p = gcd(n, d);
            this->n /= p;
            this->d /= p;
        }
    }

    ll getNumerator() { return n; }
    ll getDenominator() { return d; }

    Rational operator+(const Rational& that) const {
        ll div1 = gcd(d, that.n);
        ll div2 = gcd(n, that.d);

        ll newN = n / div2;
        ll newD = d / div1;
        ll newN2 = that.n / div1;
        ll newD2 = that.d / div2;
        
        return Rational(newN*newD2 + newN2*newD, newD*newD2);
    }

    Rational reciprocal() { return Rational(d, n); }
};

vector<ll> convertToFract(ll n) {
    
    vector<ll> f;
    ContinuedFraction currentFract, firstFract;
    
    f.push_back((ll) sqrt(n));
    firstFract = currentFract = ContinuedFraction(n, -f[0], 1, 1);
    
    do {
        //cout << f[f.size()-1] << ": " << currentFract.toString() << " to "<< currentFract.reciprocal().rationaliseDenominator().toString() << endl;
        
        currentFract = currentFract.reciprocal().rationaliseDenominator();
        ll topInt = currentFract.num.second + f[0];
        ll botInt = currentFract.den.second;
        
        // Take the integral part out
        f.push_back(topInt / botInt);
        
        currentFract = ContinuedFraction(currentFract.num.first, (topInt % botInt) - f[0], currentFract.den.first, currentFract.den.second);
    } while (currentFract != firstFract);
    
    return f;
}


ll getMinX(int d) {

    vector<ll> fracRep = convertToFract(d);
    if (fracRep.size() > 2) fracRep.pop_back();

    Rational currentFract(1, fracRep[fracRep.size()-1]);

    for (int i = (int)fracRep.size()-2; i >= 0; i--) {
        currentFract = currentFract + Rational(fracRep[i], 1);
        if (i) currentFract = currentFract.reciprocal();
    }

    return currentFract.getNumerator();
}

int main() {

    int dVal = -1;
    ll maxMinX = 0;

    for (int d = 2; d <= 1000; d++) {
        if (isPerfectSquare(d)) continue;

        ll newMinX = getMinX(d);
        if (newMinX < 0) printf("Overflow %d\n", d);

        if (newMinX > maxMinX) {
            maxMinX = newMinX;
            dVal = d;
        }
    }

    printf("%d: %lld\n", dVal, maxMinX);
    
    return 0;
}
