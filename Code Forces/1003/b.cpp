#include <iostream>
#include <string>
using namespace std;

int A, B, X;

int main() {

    cin >> A >> B >> X;

    int start = 1;
    if (X % 2 == 0 && (X/2 + 1) > A) {
        start = 0;
    }

    string s = "";
    for (int i = 0; i <= X; i++) {
        if ((i & 1) == start) {
            s += "1";
            B--;
        } else {
            s += "0";
            A--;
        }
    }

    string as(A,'0');
    string bs(B,'1');

    if (s[0] == '0') {
        cout << as + s[0] + bs + s.substr(1) << endl;
    } else {
        cout << bs + s[0] + as + s.substr(1) << endl;
    }

    return 0;
}