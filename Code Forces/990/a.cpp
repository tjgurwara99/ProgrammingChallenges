#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long N, M, A, B;
    cin >> N >> M >> A >> B;

    long long left = N % M;
    long long right = (M - left) % M;
    cout << min(left*B, right*A) << endl;

    return 0;
}
