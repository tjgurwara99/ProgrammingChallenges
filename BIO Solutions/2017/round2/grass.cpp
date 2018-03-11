#include <bits/stdc++.h>
using namespace std;

int countDistance(int x, int y) {
    if (x < 0) x *= -1;
    if (y < 0) y *= -1;
    if (x < y) swap(x, y);
    if (y == 0) return x;
    
    int p2 = x & (-x);
    return p2 + countDistance(x-p2, y);
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << countDistance(x, y) << endl;
    
    return 0;
}