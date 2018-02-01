#include <bits/stdc++.h>
using namespace std;

inline int gcd(int a, int b) {
    int c;
    while (b) {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

#define MAXN 500001
#define ll long long

int A[MAXN];

// Segment tree
int gcdTree[5*MAXN];

void buildTree(int n, int i, int j) {
    if (i == j) {
        gcdTree[n] = A[i];
    } else {
        int mid = (i+j)/2;
        buildTree(2*n, i, mid);
        buildTree(2*n+1, mid+1, j);
        gcdTree[n] = gcd(gcdTree[2*n], gcdTree[2*n+1]);
    }
}

void update(int n, int i, int j, int idx) {
    if (idx > j || idx < i) return;
    if (i == j) {
        gcdTree[n] = A[i];
    } else {
        int mid = (i+j)/2;
        update(2*n, i, mid, idx);
        update(2*n+1, mid+1, j, idx);
        gcdTree[n] = gcd(gcdTree[2*n], gcdTree[2*n+1]);
    }
}

int totalGCD(int n, int i, int j, int l, int r) {
    
    if (l > j || r < i) return -1;
    
    int mid = (i+j)/2;
    
    if (i >= l && j <= r) {
        return gcdTree[n];
    } else {
        int a = totalGCD(2*n, i, mid, l, r);
        int b = totalGCD(2*n+1, mid+1, j, l, r);
        if (a < 0) return b;
        if (b < 0) return a;
        return gcd(a, b);
    }
}

int almostCorrect(int n, int i, int j, int l, int r, int x) {
    
    cout << n << " " << i << " " << j << " " << l << " " << r << " " << x << endl;
    
    if (l > j || r < i) return -1;
    
    int mid = (i+j)/2;
    
    if (i >= l && j <= r) {
        if (i==j || gcdTree[n] % x == 0) return 1;
        if (gcdTree[2*n]%x==0 && almostCorrect(2*n+1, mid+1, j, l, r, x)) return 1;
        if (gcdTree[2*n+1]%x==0 && almostCorrect(2*n, i, mid, l, r, x)) return 1;
        
        return 0;
        
    } else {
        
        int a = almostCorrect(2*n, i, mid, l, r, x);
        if (a == 0) return 0;
        
        int b = almostCorrect(2*n+1, mid+1, j, l, r, x);
        if (b == 0) return 0;
        
        if (a == 1 && totalGCD(2*n+1, mid+1, j, mid, r)%x==0) return 1;
        if (b == 1 && totalGCD(2*n, i, mid, l, mid)%x==0) return 1;
        return 0;
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) cin >> A[i];
    
    buildTree(1, 0, N-1);
    
    int Q;
    cin >> Q;
    
    while (Q--) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            
            cout << (almostCorrect(1, 0, N-1, l-1, r-1, x) ? "YES" : "NO") << endl;
        } else {
            int i;
            cin >> i;
            cin >> A[i-1];
            
            update(1, 0, N-1, i-1);
        }
    }
    
    return 0;
}