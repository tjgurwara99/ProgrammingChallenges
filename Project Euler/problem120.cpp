#include <iostream>
using namespace std;

int main() {
    int total = 0;
    for (int a = 3; a <= 1000; a++) {
        int ans = 2;
        for (int k = 1; k <= a; k++) ans = max(ans, (2*k*a) % (a*a));
        total += ans;
    }
    cout << total << endl;
    return 0;
}