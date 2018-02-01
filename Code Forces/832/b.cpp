#include <iostream>
#include <string>
using namespace std;

bool isGood[300];
string good, match, s;
int globIdx = 0, N, T;

inline bool matchChr(char m, char c) { return m == c || (m == '?' && isGood[c]); }

inline bool isMatch() {
    int M = (int)s.size();
    
    for (int i = 0; i < globIdx; i++) {
        if (i == M || !matchChr(match[i], s[i])) return false;
    }
    
    for (int i = globIdx+1; i < N; i++) {
        int j = M - (N - i);
        if (j < globIdx || j > M || !matchChr(match[i], s[j])) return false;
    }
    
    if (globIdx < N) {
        for (int i = globIdx; i < M - (N - (globIdx+1)); i++) {
            if (isGood[s[i]]) return false;
        }
    } else if (M != N) {
        return false;
    }
    
    return true;
}

int main() {
    
    cin >> good >> match;
    
    N = (int)match.size();
    for (int i = 0; i < (int)good.size(); i++) isGood[good[i]] = true;
    while (globIdx < match.size() && match[globIdx] != '*') globIdx++;
    
    cin >> T;
    while (T--) {
        cin >> s;
        cout << (isMatch() ? "YES" : "NO") << endl;
    }
    
    return 0;
}