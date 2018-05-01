#include <bits/stdc++.h>
using namespace std;

inline int upDiv(int a, int b) { return (a%b) ? (a/b + 1) : a/b; }

int main() {
    int k, n, s, p;
    cin >> k >> n >> s >> p;
    cout << upDiv(k * upDiv(n, s), p) << endl;
    return 0;
}