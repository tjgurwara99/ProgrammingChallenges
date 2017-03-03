#include <string>
#include <algorithm>
using namespace std;

class BigInt {
    string digits;

public:

    BigInt(string digits) : digits(digits) { }

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

        return BigInt(result);
    }

    BigInt multiply(const BigInt& that) const {
        BigInt result(0);

        // TODO complete multiplication

        return result;
    }

    BigInt shiftLeft(int amount) const {
        return BigInt(string(amount,'0') + digits);
    }

    BigInt shiftRight(int amount) const {
        return BigInt(digits.substr(amount));
    }

    int digitAt(int p) const {
        if (p > (int)digits.size()) return 0;
        return digits[p]-'0';
    }

    const string& toString() const {
        return digits;
    }
};
