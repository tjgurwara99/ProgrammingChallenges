#include <iostream>
using namespace std;

int main() {
    
    string s;
    cin >> s;
    
    int n = (int)s.size();
    
    bool possible = false;
    
    for (int i = 0; i < n-2; i++) {
        if (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2] && s[i] != '.' && s[i+1] != '.' && s[i+2] != '.') {
            possible = true;
            break;
        }
    }
    
    cout << (possible ? "Yes\n" : "No\n");
    
    return 0;
}