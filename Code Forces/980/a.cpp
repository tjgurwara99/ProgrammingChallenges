#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int links = 0, pearls = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '-') links++;
        else pearls++;
    }
    
    cout << ((pearls == 0 || links % pearls == 0) ? "YES" : "NO") << endl;
}