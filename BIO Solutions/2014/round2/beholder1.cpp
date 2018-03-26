#include <bits/stdc++.h>
using namespace std;

#define MAXN 70000

string input;
int N, charCounts[26];
int charsLeft[26];
int palHalf[MAXN];

int main() {
    
    cin >> input;
    N = (int)input.size();
    for (int i = 0; i < N; i++) charCounts[input[i]-'A']++;
    
    int oddChar = -1;
    for (int i = 0; i < 26; i++) {
        charsLeft[i] = charCounts[i]/2;
        if (charCounts[i] % 2) oddChar = i;
    }
    
    bool isEqual = true;
    
    for (int i = 0; i < N/2; i++) {
        
        int j = input[i] - 'A';
        while (!charsLeft[j]) j++;
        
        if (j != input[i]-'A') isEqual = false;
        charsLeft[j]--;
        palHalf[i] = j;
    }
    
    if (N % 2 == 1 && charCounts[input[N/2]] % 2 == 0) {
        isEqual = false;
    }
    
    if (isEqual) {
        bool advance = true;
        for (int i = N/2-1; i >= 0; --i) {
            if (input[N-i-1] > input[i]) {
                break;
            } else if (input[N-i-1] < input[i]) {
                advance = false;
                break;
            }
        }
        
        if (advance) {
            next_permutation(palHalf, palHalf + N/2);
        }
    }
    
    for (int i = 0; i < N/2; i++) printf("%c", palHalf[i]+'A');
    if (N % 2) printf("%c", oddChar + 'A');
    for (int i = 0; i < N/2; i++) printf("%c", palHalf[N/2-i-1]+'A');
    printf("\n");
    
    return 0;
}