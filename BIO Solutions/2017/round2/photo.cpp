#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000

int P[MAXN], indexOf[MAXN], permCount[MAXN];

void nextPerm(int n) {
    
    if (n == 2) {
        swap(P[indexOf[1]], P[indexOf[2]]);
        return;
    }
    
    int maxIdx = 0, nextIdx = n, prevIdx = -1;
    for (int i = 1; i < n; i++) {
        if (indexOf[i] < indexOf[n]) {
            maxIdx++;
            if (indexOf[i] > prevIdx) {
                prevIdx = indexOf[i];
            }
        } else if (indexOf[i] < nextIdx) {
            nextIdx = indexOf[i];
        }
    }
    
    if (permCount[n-1] % 2) {
        if (nextIdx == n) {
            nextPerm(n-1);
        } else {
            swap(P[indexOf[n]], P[nextIdx]);
        }
    } else {
        if (prevIdx == -1) {
            nextPerm(n-1);
        } else {
            swap(P[indexOf[n]], P[prevIdx]);
        }
    }
}

int main() {
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        indexOf[P[i]] = i;
    }
    
    permCount[2] = (indexOf[2] > indexOf[1]) ? 0 : 1;
    for (int n = 3; n <= N; n++) {
        int maxIdx = 0;
        for (int i = 1; i < n; i++) {
            if (indexOf[i] < indexOf[n]) maxIdx++;
        }
        permCount[n] = n*permCount[n-1] +
            ((permCount[n-1] % 2) ? maxIdx : (n-1-maxIdx));
    }
    
    nextPerm(N);
    for (int i = 0; i < N-1; i++) cout << P[i] << " ";
    cout << P[N-1] << endl;
    
    
    return 0;
}