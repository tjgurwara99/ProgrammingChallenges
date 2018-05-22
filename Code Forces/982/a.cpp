#include <iostream>
using namespace std;

int main() {
    
    int N;
    string s;
    cin >> N >> s;
    
    bool valid = true;
    for (int i = 0; i < N; i++) {
        int count = 0;
        if (i && s[i-1] == '1') count++;
        if (i<N-1 && s[i+1] == '1') count++;
        
        if ((s[i] == '1' && count > 0) || (s[i] == '0' && count == 0)) {
            valid = false;
            break;
        }
    }
    
    cout << (valid ? "Yes\n" : "No\n");
    
    return 0;
}