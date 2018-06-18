#include <iostream>
#include <algorithm>
using namespace std;

#define MAXL 400000

int N, depthCount[MAXL], reverseDepthCount[MAXL];

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        bool valid = true;
        int depth = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            if (s[j] == '(') depth++;
            else depth--;
            if (depth < 0) {
                valid = false;
                break;
            }
        }
        if (valid) depthCount[depth]++;

        valid = true;
        depth = 0;
        for (int j = (int)s.size()-1; j >= 0; j--) {
            if (s[j] == ')') depth++;
            else depth--;
            if (depth < 0) {
                valid = false;
                break;
            }
        }
        if (valid) reverseDepthCount[depth]++;
    }

    long long ans = 0;
    for (int i = 0; i < MAXL; i++) {
        ans += ((long long)depthCount[i]) * reverseDepthCount[i];
    }
    cout << ans << endl;

    return 0;
}
