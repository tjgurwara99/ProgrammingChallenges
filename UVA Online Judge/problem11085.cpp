#include <cstdio>

int pos[8], cols[8], bestAns;

void solve(int r, int mask) {
    if (r == 8) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            if (cols[i] != pos[i]) cnt++;
        }
        if (cnt < bestAns) bestAns = cnt;
        return;
    }
    
    int subMask = mask;
    for (int i = 0; i < r; i++) {
        int a = cols[i]+r-i, b = cols[i]-r+i;
        if (a < 8) subMask &= ~(1 << a);
        if (b >= 0) subMask &= ~(1 << b);
    }
    for (int i = 0; i < 8; i++) {
        if (subMask & (1 << i)) {
            cols[r] = i;
            solve(r+1, mask & (~(1 << i)));
        }
    }
}

int main() {
    
    int t = 0;
    while (scanf("%d", &pos[0]) != EOF) {
        for (int i = 1; i < 8; i++) scanf("%d", &pos[i]);
        for (int i = 0; i < 8; i++) pos[i]--;
        bestAns = 8;
        solve(0, (1<<8)-1);
        printf("Case %d: %d\n", ++t, bestAns);
    }
    
    return 0;
}