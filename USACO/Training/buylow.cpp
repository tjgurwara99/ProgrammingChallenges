/*
ID: basimkh1
PROG: buylow
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

class BigInt {
    string digits;

public:

    BigInt() { digits = "0"; }

    BigInt(const string& digits) : digits(digits) { }

    BigInt(long long v) { digits = to_string(v); }

    BigInt add(const BigInt& that) const {
        string result(max(digits.size(), that.digits.size())+1, '0');

        bool carry = false;
        for (int i = 0; i < (int)result.length(); i++) {
            int sum = digitAt(i)+that.digitAt(i);
            if (carry) {
                sum++;
                carry = false;
            }

            if (sum >= 10) {
                sum -= 10;
                carry = true;
            }
            result[i] = '0'+sum;
        }
        while (result.length() > 1 && result[result.length()-1] == '0') {
            result.pop_back();
        }

        return BigInt(result);
    }

    int digitAt(int p) const {
        if (p >= (int)digits.size()) return 0;
        return digits[p]-'0';
    }

    const string toString() const {
        string temporary = digits;
        reverse(temporary.begin(), temporary.end());
        return temporary;
    }
};

#define MAXN 6000

int N, A[MAXN], DP[MAXN];
BigInt cnt[MAXN];

int main() {
    
    //freopen("buylow.in", "r", stdin);
    //freopen("buylow.out", "w", stdout);
    map<int, int> previous;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    A[N] = 0;
    
    for (int i = 0; i <= N; i++) {
        DP[i] = 1;
        
        previous.clear();
        for (int j = 0; j < i; j++) {
            if (A[j] <= A[i]) continue;
            
            int v = DP[j]+1;
            if (v < DP[i]) continue;
            
            if (v > DP[i]) {
                previous.clear();
                DP[i] = v;
            }
            previous[A[j]] = j;
        }
        
        if (!previous.empty()) {
            cnt[i] = BigInt(0);
            for (auto const& p: previous) {
                cnt[i] = cnt[i].add(cnt[p.second]);
            }
        } else {
            cnt[i] = BigInt(1);
        }
    }
    
    cout << DP[N]-1 << " " << cnt[N].toString() << endl;
    
    return 0;
}