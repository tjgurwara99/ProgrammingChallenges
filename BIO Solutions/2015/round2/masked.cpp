#include <bits/stdc++.h>
using namespace std;


int main() {
    
    string input, output = "";
    cin >> input;
    
    int j = 0;
    for (int i = 0; i < (int)input.size(); i++) {
        if (tolower(input[i]) == "masked"[j]) {
            j++;
            if (j == 6) {
                
                int alpha = 0;
                for (int k = i-4; k <= i; k++) {
                    alpha *= 2;
                    if (input[k] < 'a') alpha += 1;
                }
                
                alpha--;
                output += (input[i-5] == 'm') ? ('a'+alpha) : ('A'+alpha);
                j = 0;
            }
        } else {
            for (int k = i-j; k <= i; k++) output += input[k];
            j = 0;
        }
    }
    
    cout << output << endl;
    
    return 0;
}