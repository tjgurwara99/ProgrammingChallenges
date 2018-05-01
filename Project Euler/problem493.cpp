#include <cstdio>

double NCR[71][71], noWays[8];

int main() {
    
    for (int i = 1; i <= 70; i++) {
        NCR[i][0] = NCR[i][i] = 1;
        for (int j = 1; j < i; j++) {
            NCR[i][j] = NCR[i-1][j] + NCR[i-1][j-1];
        }
    }
    
    double total = 0;
    for (int i = 2; i <= 7; i++) {
        noWays[i] = NCR[i*10][20];
        for (int j = 2; j < i; j++) noWays[i] -= NCR[i][j] * noWays[j];
        total += i * noWays[i] * NCR[7][i];
    }
    
    printf("%0.9f\n", total / NCR[70][20]);
    
    return 0;
}