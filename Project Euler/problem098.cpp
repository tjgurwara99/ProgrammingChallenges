/* Correct answer in 25s */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

char words[2000][30];
int lens[2000];
int tenPow[10];
vector<int> wordsByLen[30];

bool isAnagram(int strA, int strB) {
    int count[26];
    for (int i = 0; i < 26; i++) count[i] = 0;
    
    for (int i = 0; i < lens[strA]; i++) count[words[strA][i]-'A']++;
    for (int i = 0; i < lens[strB]; i++) count[words[strB][i]-'A']--;
    
    for (int i = 0; i < 26; i++) if (count[i] != 0) return false;
    return true;
}

inline bool isSquare(int n) {
    double root = sqrt(n);
    return (int)(root) == root;
}

int pSquareA;
int pSquareB;

bool checkSquareAnagram(int strA, int strB) {
    
    int charIdx[26];
    int currentCharIdx = 0;
    for (int i = 0; i < 26; i++) charIdx[i] = -1;

    for (int i = 0; i < lens[strA]; i++) {
        int c = words[strA][i]-'A';
        if (charIdx[c] == -1) charIdx[c] = currentCharIdx++;
    }
    
    int fstA = charIdx[words[strA][0]-'A'];
    int fstB = charIdx[words[strB][0]-'A'];
    int values[10], seen;
    
    for (int i = 0; i < tenPow[currentCharIdx]; i++) {
        int k = i % 10;
        if (k == 0 || k == 2 || k == 3 || k == 7 || k == 8) continue;
        seen = 0;
        bool valid = true;
        for (int j = 0, n = i; j < currentCharIdx; n /= 10, j++) {
            values[j] = n % 10;
            if (seen & (1 << values[j])) {
                valid = false;
                break;
            }
            seen |= 1 << values[j];
        }
        if (!valid || values[fstA] == 0 || values[fstB] == 0) continue;
        
        int aVal = 0, bVal = 0;
        for (int j = 0; j < lens[strA]; j++) aVal = aVal*10 + values[charIdx[words[strA][j]-'A']];
        if (!isSquare(aVal)) continue;
        
        for (int j = 0; j < lens[strB]; j++) bVal = bVal*10 + values[charIdx[words[strB][j]-'A']];
        if (isSquare(bVal)) {
            pSquareA = aVal;
            pSquareB = bVal;
            return true;
        }
    }
    
    return false;
}

int main() {
    
    FILE *fin = fopen("p098_words.txt", "r");
    
    tenPow[0] = 1;
    for (int i = 1; i < 10; i++) tenPow[i] = 10*tenPow[i-1];
    
    for (int i = 0; fscanf(fin, " \" %[^,\"]\", ", words[i]) != EOF; i++) {
        lens[i] = strlen(words[i]);
        wordsByLen[lens[i]].push_back(i);
    }
    
    for (int l = 1; l < 20; l++) {
        int n = (int)wordsByLen[l].size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int a = wordsByLen[l][i];
                int b = wordsByLen[l][j];
                if (isAnagram(a, b) && checkSquareAnagram(a, b)) {
                    printf("%s %s %d %d\n", words[a], words[b], pSquareA, pSquareB);
                }
            }
        }
    }
    
    fclose(fin);
    return 0;
}
