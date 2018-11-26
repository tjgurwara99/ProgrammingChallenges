#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    sort(s.begin(), s.end());
    
    cout << s << endl;
    return 0;
}