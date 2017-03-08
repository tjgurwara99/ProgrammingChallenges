#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
pair<string,int> digitWords[10];
int tenPow[10];

int countPrefix(int ans) {
    if (ans == 0) return 1;
    
    int totalCount = ans > N ? 0 : 1;
    
    for (int d = 0; ans*10 <= N; d++) {
        ans *= 10;
        totalCount += min(tenPow[d+1], N-ans+1);
    }
    
    return totalCount;
}

int main() {
    tenPow[0] = 1;
    for (int i = 1; i < 10; i++) tenPow[i] = 10*tenPow[i-1];
    
    cin >> N >> M;
    for (int i = 0; i < 10; i++) {
        cin >> digitWords[i].first;
        digitWords[i].second = i;
    }
    sort(digitWords, digitWords+10);
    
    int ans = 0;
    int idx = M;
    
    do {
        idx--;
        for (int i = 0; i < 10; i++) {
            int d = digitWords[i].second;
            int count = countPrefix(ans*10+d);
            
            if (idx >= count) {
                idx -= count;
            } else {
                ans = ans*10+d;
                break;
            }
        }
    } while (idx);
    
    cout << ans << endl;
    
    return 0;
}