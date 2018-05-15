/*
ID: basimkh1
PROG: window
LANG: C++11
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct window {
    char id;
    int x1, y1, x2, y2;
    
    window() {}
    
    window(int a, int b, int c, int d) {
        x1 = min(a, c);
        x2 = max(a, c);
        y1 = min(b, d);
        y2 = max(b, d);
    }
    
    int area() { return (x2 - x1) * (y2 - y1); }
};

vector<window> windows;

int windowAreaVisible(int pos) {
    vector<window> rects, newRects;
    rects.push_back(windows[pos]);
    
    for (int i = pos+1; i < (int)windows.size(); i++) {
        window& w = windows[i];
        
        newRects.clear();
        for (const window& r: rects) {
            
            // disjoint
            if (w.x1 >= r.x2 || w.x2 <= r.x1 || w.y1 >= r.y2 || w.y2 <= r.y1) {
                newRects.push_back(r);
                continue;
            }
            
            // intersection
            int x1 = max(w.x1, r.x1);
            int y1 = max(w.y1, r.y1);
            int x2 = min(w.x2, r.x2);
            int y2 = min(w.y2, r.y2);
            
            // up to 4 new ones
            if (y1 > r.y1) newRects.push_back(window(r.x1, r.y1, r.x2, y1));
            if (x1 > r.x1) newRects.push_back(window(r.x1, y1, x1, y2));
            if (x2 < r.x2) newRects.push_back(window(x2, y1, r.x2, y2));
            if (y2 < r.y2) newRects.push_back(window(r.x1, y2, r.x2, r.y2));
        }
        
        swap(rects, newRects);
    }
    
    int total = 0;
    for (window& r: rects) total += r.area();
    return total;
}

int main() {
    
    freopen("window.in", "r", stdin); freopen("window.out", "w", stdout);
    
    char buffer[100];
    
    while (scanf(" %s", buffer) != EOF) {
        char op = buffer[0];
        
        if (op == 'w') {
            window w;
            sscanf(buffer+1, "(%c,%d,%d,%d,%d)", &w.id, &w.x1, &w.y1, &w.x2, &w.y2);
            
            if (w.x1 > w.x2) swap(w.x1, w.x2);
            if (w.y1 > w.y2) swap(w.y1, w.y2);
            
            windows.push_back(w);
        } else {
            char windowID;
            sscanf(buffer+1, "(%c)", &windowID);
            
            int pos = 0;
            while (windows[pos].id != windowID) pos++;
            
            if (op == 't') {
                while (pos < (int)windows.size()-1) {
                    swap(windows[pos], windows[pos+1]);
                    pos++;
                }
            } else if (op == 'b') {
                while (pos > 0) {
                    swap(windows[pos], windows[pos-1]);
                    pos--;
                }
            } else if (op == 'd') {
                windows.erase(windows.begin()+pos);
            } else {
                int shownArea = windowAreaVisible(pos);
                printf("%.3f\n", (shownArea * 100.0) / windows[pos].area());
            }
        }
    }
    
    return 0;
}