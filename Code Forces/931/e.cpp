#include <bits/stdc++.h>
using namespace std;

#define MAXN 6000

string S;
int N, charsFound[26][MAXN][26], charOffset[26];

int main() {
    
    cin >> S;
    N = (int)S.size();
    
    for (int i = 0; i < N; i++) {
        int c = S[i]-'a';
        for (int j = 0; j < N; j++) {
            int d = S[(i+j)%N]-'a';
            charsFound[c][j][d]++;
        }
    }
    
    // choose index for each character
    for (int c = 0; c < 26; c++) {
        
        int bestOffset = 0, bestScore = -1;
        
        for (int o = 0; o < N; o++) {
            int score = 0;
            for (int d = 0; d < 26; d++) {
                if (charsFound[c][o][d] == 1) score++;
            }
            
            if (score > bestScore) {
                bestScore = score;
                bestOffset = o;
            }
        }
        
        charOffset[c] = bestOffset;
    }
    
    int count = 0;
    for (int i = 0; i < N; i++) {
        int c = S[i]-'a';
        int o = charOffset[c];
        int d = S[(i+o)%N]-'a';
        
        if (charsFound[c][o][d] == 1) count++;
    }
    
    double ans = (count * 1.0) / N;
    printf("%0.10f\n", ans);
    
    return 0;
}