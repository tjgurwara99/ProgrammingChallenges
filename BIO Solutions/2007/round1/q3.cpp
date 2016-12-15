#include <cstdio>
#include <queue>
using namespace std;

struct Shirts {
    char a[7];
    
    Shirts (int n) {
        for (int i = 6; i >= 0; i--) {
            a[i] = (n % 10) + '0';
            n /= 10;
        }
    }
    
    int toInt() const {
        int n = 0;
        for (int i = 0; i < 7; i++) {
            n = n*10 + (a[i]-'0');
        }
        return n;
    }
    
    void firstOp() {
        char tmp = a[0];
        for (int i = 0; i < 3; i++) a[i] = a[i+1];
        a[3] = tmp;
    }
    
    void secondOp() {
        char tmp = a[6];
        for (int i = 6; i >= 4; i--) a[i] = a[i-1];
        a[3] = tmp;
    }
    
    void thirdOp() {
        char tmp = a[3];
        for (int i = 3; i >= 1; i--) a[i] = a[i-1];
        a[0] = tmp;
    }
    
    void fourthOp() {
        char tmp = a[3];
        for (int i = 3; i <= 5; i++) a[i] = a[i+1];
        a[6] = tmp;
    }
    
    Shirts copy() const { return Shirts(toInt()); }
};

bool seen[10000000];

int main() {
    
    queue<pair<Shirts,int> > opStack;
    
    int n;
    scanf("%d", &n);
    
    opStack.push(make_pair(Shirts(n), 0));
    
    while (true) {
        pair<Shirts, int>& next = opStack.front();
        int v = next.first.toInt();
        if (v == 1234567) {
            printf("%d\n", next.second);
            break;
        }
        seen[v] = true;
        
        int d = next.second + 1;
        opStack.pop();
        
        Shirts a(v);
        a.firstOp();
        if (!seen[a.toInt()]) opStack.push(make_pair(a, d));
        
        Shirts b(v);
        b.secondOp();
        if (!seen[b.toInt()]) opStack.push(make_pair(b, d));
        
        Shirts c(v);
        c.thirdOp();
        if (!seen[c.toInt()]) opStack.push(make_pair(c, d));
        
        Shirts k(v);
        k.fourthOp();
        if (!seen[k.toInt()]) opStack.push(make_pair(k, d));
    }
    
    return 0;
}