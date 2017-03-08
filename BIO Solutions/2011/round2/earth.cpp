#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
pair<string,int> digitWords[10];
int tenPow[10];

int digitCount(int d) {
    
    if (d == 0) return 1;
    
    int totalCount = 0;
    int dc = 1;
    
    while (tenPow[dc] <= N) {
        totalCount += tenPow[dc-1];
        dc++;
    }
    dc--;
    
    int fd = N / tenPow[dc];
    if (fd == d) {
        totalCount += (N % tenPow[dc]) + 1;
    } else if (fd > d) {
        totalCount += tenPow[dc];
    }
    
    return totalCount;
}

int countPrefix(int number, int ans) {
    
    if (ans == 0) return 1;
    
    int dc = 0;
    int totalCount = ans > number ? 0 : 1; // include ans
    
    while (ans*10 <= number) {
        ans *= 10;
        dc++;
        totalCount += min(tenPow[dc], number-ans+1);
    }
    
    return totalCount;
}

int getNext(int n, int digit) {
    int i = 0;
    while (tenPow[i+1] <= n) i++;
    
    if (digit == n) return n % tenPow[i];
    if (digit < n) return tenPow[i]-1;
    
    return i == 0 ? 0 : tenPow[i-1];
}

int main() {
    tenPow[0] = 1;
    for (int i = 1; i < 10; i++) tenPow[i] = 10*tenPow[i-1];
    
    for (int i = 0; i < 10; i++) {
        cin >> digitWords[i].first;
        digitWords[i].second = i;
    }
    sort(digitWords, digitWords+10);
    
    int ans = 0;
    int idx = M;
    bool first = true;
    
    for (int i = 0; i < 10; i++) {
        
    }
    
    
    int currentN = N;
    
    while (idx) {
        idx--;
        
        int i;
        for (i = 0; i < 10; i++) {
            if (digitWords[i].second == 0 && first) continue;
            
            int dc = digitCount(digitWords[i].second, currentN);
            if (idx >= dc) {
                idx -= dc;
            } else {
                ans = ans*10+digitWords[i].second;
                break;
            }
        }
        
        currentN = getNext(currentN, i);
        first = false;
    }
    
    cout << ans << endl;
    
    return 0;
}