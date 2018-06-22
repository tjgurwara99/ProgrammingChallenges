#include <iostream>
using namespace std;

struct quad {
    pair<int,int> points[4];
    
    void read() {
        for (int i = 0; i < 4; i++) {
            cin >> points[i].first >> points[i].second;
        }
    }
    
    int cross(int a, int b, int c, int d) {
        return a*d - b*c;
    }
    
    int sgn(int x) {
        if (x < 0) return -1;
        if (x > 0) return 1;
        return 0;
    }
    
    bool contains(int x, int y) {
        int side = 0;
        for (int i = 0; i < 4; i++) {
            int j = (i+1)%4;
            int a = points[j].first - points[i].first;
            int b = points[j].second - points[i].second;
            int c = x - points[i].first;
            int d = y - points[i].second;
            int v = sgn(cross(a, b, c, d));
            
            if (v == 0) {
                continue;
            }
            
            if (side == 0) {
                side = v;
            } else if (side != v) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    
    quad A, B;
    A.read(); B.read();
    
    for (int x = -100; x <= 100; x++) {
        for (int y = -100; y <= 100; y++) {
            if (A.contains(x,y) && B.contains(x,y)) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    
    cout << "NO\n";
    return 0;
}