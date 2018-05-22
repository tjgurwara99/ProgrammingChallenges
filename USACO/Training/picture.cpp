/*
ID: basimkh1
PROG: picture
LANG: C++11
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct rect {
    int x1,y1,x2,y2;
    void change() {
        swap(x1,y1); swap(x2,y2);
        fix();
    }
    void fix() {
        if (x1 > x2) swap(x1,x2);
        if (y1 > y2) swap(y1, y2);
    }
    bool operator<(const rect& other) const {
        if (x1 < other.x1) return true;
        if (x1 > other.x1) return false;
        return y1 < other.y1;
    }
};

int N; 
vector<rect> R;

inline int sumXPerim() {
    int total = 0;
    for (int y = -10000; y < 10000; y++) {
        int extent = -20000;
        for (int i = 0; i < N; i++) {
            if (R[i].y1 > y || R[i].y2 <= y) continue;
            int x1 = R[i].x1, x2 = R[i].x2;
            if (x1 > extent) {
                total += 2;
                extent = x2;
            } else {
                extent = max(extent, x2);
            }
        }
    }
    return total;
}

int main() {
    
    freopen("picture.in", "r", stdin); freopen("picture.out", "w", stdout);
    
    scanf("%d",&N);
    for (int i = 0; i < N; i++) {
        rect r;
        scanf("%d %d %d %d", &r.x1, &r.y1, &r.x2, &r.y2);
        R.push_back(r);
    }
    sort(R.begin(), R.end());
    
    int ans = sumXPerim();
    for (int i = 0; i < N; i++) R[i].change();
    sort(R.begin(), R.end());
    ans += sumXPerim();
    printf("%d\n", ans);
    
    return 0;
}