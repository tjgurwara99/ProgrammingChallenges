#include <iostream>
#include <string>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define MAXN 2000000

const int MOD = (int)(1e9+7);

int charFreq[26];

int factorialDP[MAXN], lastSeen = 0;
inline int factorial(int k) {
    FOR(i,lastSeen+1,k+1) factorialDP[i] = (int)(((long long)factorialDP[i-1] * i) % MOD);
    return factorialDP[k];
}

inline int egcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x2, y2, g = egcd(b, a % b, x2, y2);
    x = y2;
    y = x2 - (a/b) * y2;
    return g;
}

inline int modInv(int k) {
    int x, y, g = egcd(MOD, k, x, y);
    while (y < 0) y += MOD;
    return y;
}

inline int countPerms() {
    int total = 0;
    FOR(i,0,26) total += charFreq[i];
    long long a = factorial(total);
    FOR(i,0,26) a = (a * modInv(factorial(charFreq[i]))) % MOD;
    return (int)a;
}

inline int permCount(string S) {
    int N = (int)S.size();
    FOR(i,0,26) charFreq[i] = 0;
    FOR(i,0,N) charFreq[S[i]-'a']++;
    int ans = 0;
    FOR(i,0,N) {
        FOR(j,0,S[i]-'a') {
            if (charFreq[j]) {
                charFreq[j]--;
                ans = (ans + countPerms()) % MOD;
                cout << i << " " << j << endl;
                charFreq[j]++;
            }
        }
        charFreq[S[i]-'a']--;
    }
    return ans;
}

int main() {

    factorialDP[0] = 1;

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string A, B;
    cin >> A >> B;

    int ans = (permCount(B) - permCount(A) + 1) % MOD;
    while (ans < 0) ans += MOD;
    cout << ans << endl;

    return 0;
}