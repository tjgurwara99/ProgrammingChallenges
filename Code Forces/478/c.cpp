#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    long long b[3];
    cin >> b[0] >> b[1] >> b[2];
    
    sort(b, b+3);
    cout << ((b[2] > (b[1] + b[0])*2) ? (b[0]+b[1]) : (b[0]+b[1]+b[2])/3) << endl;
    
    return 0;
}