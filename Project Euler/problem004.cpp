#include <iostream>
using namespace std;

int rev(int n) {
    int r = 0;
    for (; n; n /= 10) r = 10*r + n%10;
    return r;
}
    
bool isPalin(int num) { return rev(num) == num; }

int highPalin() {
    for (int a = 999; a >= 100; a--) {
        int diff = a % 11 == 0 ? 1 : 11;
        for (int b = a - a%11; b >= 100; b-=diff) {
            if (isPalin(a*b)) return a*b;
        }
    }
    return -1;
}

int main() {
    cout << highPalin() << endl;
    return 0;
}
