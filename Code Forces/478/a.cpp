#include <iostream>
using namespace std;

int main() {
    
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    
    int t = a+b+c+d+e;
    cout << ((t%5 || !t) ? (-1) : (t/5)) << endl;
    
    return 0;
}