#include <bits/stdc++.h>
using namespace std;

int N, M, sCount, eCount, V;
int stairs[200000], elevators[200000];

int r1, c1, r2, c2;

inline int stairCost(int i) {
    if (i < 0 || i >= sCount) return INT_MAX;
    // cout << "stair " << i << endl;
    int c =  abs(c1 - stairs[i]) + abs(r2 - r1) + abs(c2 - stairs[i]);
    // cout << "cost " << c << endl; 
    return c;
}

inline int elevatorCost(int i) {
    if (i < 0 || i >= eCount) return INT_MAX;
    // cout << "elevator " << i << endl;
    
    int diff = abs(r2-r1);
    int moveCost = diff/V + ((diff%V) ? 1 : 0);
    int c = abs(c1 - elevators[i]) + abs(c2 - elevators[i]) + moveCost;
    // cout << c1 << " " << c2 << " " << elevators[i] << endl;
    // cout << "cost " << c << " moveCost " << moveCost << endl; 
    return c;
}

inline int findNext(int* arr, int arrSize, int v) {
    return (int)(lower_bound(arr, arr+arrSize, v)-arr);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> sCount >> eCount >> V;
    
    for (int i = 0; i < sCount; i++) cin >> stairs[i];
    for (int i = 0; i < eCount; i++) cin >> elevators[i];
    
    int Q;
    cin >> Q;
    
    while (Q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        
        int ans = INT_MAX;
        
        int a = findNext(stairs, sCount, c1);
        int b = findNext(stairs, sCount, c2);
        ans = min(ans, stairCost(a));
        ans = min(ans, stairCost(a-1));
        ans = min(ans, stairCost(b));
        ans = min(ans, stairCost(b-1));
        
        int c = findNext(elevators, eCount, c1);
        int d = findNext(elevators, eCount, c2);
        ans = min(ans, elevatorCost(c));
        ans = min(ans, elevatorCost(c-1));
        ans = min(ans, elevatorCost(d));
        ans = min(ans, elevatorCost(d-1));
        
        cout << ans << "\n";
    }
    
    
    return 0;
}