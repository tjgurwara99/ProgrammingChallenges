#include <cstdio>
using namespace std;

#define ll long long
ll ninePow[20];
ll digitCount[20]; // Number of upside down numbres in no.s of digit N

void printNthNum(int n) {
    
    if (n <= 1) {
        printf("5");
        return;
    }
    
    int d = 0, i;
    for (i = 0; n > d + digitCount[i]; i++) d += digitCount[i];
    
    // i = no. of digits in n
    int offset = n - d;
    int perDigit = digitCount[i]/9;
    int firstDigit = offset / perDigit;
    
    printf("%d",firstDigit);
    printNthNum(offset % perDigit);
    printf("%d",10-firstDigit);
}

int main() {
    
    ninePow[0] = 1;
    for (int i = 1; i < 15; i++) ninePow[i] = ninePow[i-1]*9;
    
    for (int i = 1; i < 15; i++) digitCount[i] = ninePow[i/2];
    
    int n;
    scanf("%d", &n);
    
    printNthNum(n);
    printf("\n");
    
    //printf("%d %d\n", i, d);
    
    return 0;
}