#include<iostream>
using namespace std;

#define N 600851475143
#define ll long long

ll hPrimeFactor(ll n) {
    ll nnum = n, hFact = 0;
    int counter = 2;
    for (int counter = 2; counter*counter <= nnum; counter++) {
        while (nnum % counter == 0) {
            nnum = nnum / counter;
            hFact = counter;
        } 
    }
    if (nnum > hFact) hFact = nnum;
    return hFact;
}        

int main() {   
    cout << hPrimeFactor(N) << endl;
    return 0;
}

