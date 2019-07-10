#include <iostream>
using namespace std;

#define MAX 4000000

int main() {
    long long sum = 0, fibA = 0, fibB = 1;
    while (fibB <= MAX) {
        sum += fibB;
        ll fibC = fibA + fibB;
        fibA = fibB;
        fibB = fibC;
    }
    cout << sum << endl;
    return 0;
}
