#include <iostream>
#include <set>
using namespace std;

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    set<int> nums;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a != 0) nums.insert(a);
    }
    
    cout << (int)nums.size() << endl;
    
    return 0;
}