#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int digitSum(int n) {
    int total = 0;
    for (; n; n /= 10) total += n % 10;
    return total;
}

int main() {
    int n;
    cin >> n;
    
    int ans = 0;
    for (int i = max(0, n-100); i <= n; i++) {
        if (digitSum(i) + i == n) ans++;
    }
    cout << ans << endl;;
    for (int i = max(0, n-100); i <= n; i++) {
        if (digitSum(i) + i == n) cout << i << endl;
    }
    
    return 0;
}