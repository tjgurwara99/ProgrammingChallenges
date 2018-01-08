#include <iostream>
#include <algorithm>
using namespace std;
int ans() {
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    if (n==1) return 0;
    return min(a,b) + min(a, min(b,c))*(n-2);
}
int main() {
    cout << ans() << endl;
    return 0;
}