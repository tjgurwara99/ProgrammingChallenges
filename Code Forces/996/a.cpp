#include <iostream>
using namespace std;

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    int ans = 0;
    for (int v: { 100, 20, 10, 5, 1}) {
        ans += n/v;
        n -= v * (n/v);
    }
    
    cout << ans << endl;
    
    return 0;
}