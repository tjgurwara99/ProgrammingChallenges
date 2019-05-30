#include <iostream>
using namespace std;

bool isprime(int n) {   
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
 
long long nthprime(int n) {
    long long i=2;     
    while (n) {
        i = (i == 2) ? 3 : i+2;
        if(isprime(i)) counter++;
    }
    return i;
}

int main() {
    cout << nthprime(10001) << endl;
    return 0;
}
