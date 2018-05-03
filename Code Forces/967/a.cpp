#include <bits/stdc++.h>
using namespace std;

int pos[2000];

int main() {
    
    int N, S;
    cin >> N >> S;
    
    for (int i = 0; i < N; i++) {
        int h, m;
        cin >> h >> m;
        m += 60*h;
        pos[m]++;
    }
    
    for (int i = 0; ; i++) {
        bool blocked = false;
        for (int j = max(0, i-S); j < 2000 && j <= i+S; j++) {
            if (pos[j]) {
                blocked = true;
                break;
            }
        }
        
        if (!blocked) {
            cout << (i/60) << " " << (i%60) << endl;
            break;
        }
    }
    
    return 0;
}