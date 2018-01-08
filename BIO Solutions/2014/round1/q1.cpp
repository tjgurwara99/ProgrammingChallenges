#include <bits/stdc++.h>
using namespace std;

#define MAXN 50000

pair<int,int> solve(int n) {
    
    vector<int> nums;
    for (int i = 1; i < MAXN; i += 2) nums.push_back(i);
    
    int bestBefore = 0, i;
    for (i = 1; nums[i] <= n; i++) {
        int x = nums[i];
        for (int j = x-1; j < nums.size(); j += x-1) {
            nums.erase(nums.begin()+j);
        }
        if (nums[i] < n) bestBefore = i;
    }
    
    return make_pair(nums[bestBefore], nums[i]);
}

int main() {
    
    int n;
    cin >> n;
    
    pair<int,int> ans = solve(n);
    cout << ans.first << " " << ans.second << endl;
    
    return 0;
}