#include <cstdio>
using namespace std;

#define ll long long
ll ninePow[30];
ll digitCount[30]; // Number of upside down numbres in no.s of digit N

void printNthNum(ll n, int digits) {
    
    if (digits <= 0) return;
    if (digits == 1) {
        printf("5");
        return;
    }
    
    ll perDigit = digitCount[digits]/9L;
    int firstDigit = (int)(n / perDigit) + 1;
    
    printf("%d",firstDigit);
    printNthNum(n % perDigit, digits - 2);
    printf("%d",10-firstDigit);
}

int main() {
    
    ninePow[0] = 1;
    for (int i = 1; i < 30; i++) ninePow[i] = ninePow[i-1]*9;
    
    for (int i = 1; i < 30; i++) digitCount[i] = ninePow[i/2];
    
    int n;
    scanf("%d", &n);
    
    ll d = 0;
    int i;
    for (i = 0; n > d + digitCount[i]; i++) d += digitCount[i];
    
    printNthNum(n-d-1, i);
    printf("\n");
    
    return 0;
}