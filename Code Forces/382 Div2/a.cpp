#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() { 

    int n, k;
    string line;

    cin >> n >> k >> line;

    bool foundFirst = false;
    bool reached = false;

    for (int i = 0; i < n; i += foundFirst ? k : 1) {
        if (!foundFirst) {
            if (line[i] == 'G' || line[i] == 'T') {
                foundFirst = true;
            }
        } else {
            if (line[i] == 'G' || line[i] == 'T') {
                reached = true;
                break;
            }
            if (line[i] == '#') break;
        }
    }

    cout << (reached ? "YES" : "NO") << endl;

    return 0;
}
