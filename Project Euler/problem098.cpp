#include <cstdio>
#include <cstring>
#include <vector>

char words[2000][30];
int lens[2000];

std::vector<int> wordsByLen[30];

bool isAnagram(int strA, int strB) {
    int count[26];
    for (int i = 0; i < 26; i++) count[i] = 0;
    
    for (int i = 0; i < lens[strA]; i++) count[words[strA][i]-'A']++;
    for (int i = 0; i < lens[strB]; i++) count[words[strB][i]-'A']--;
    
    for (int i = 0; i < 26; i++) if (count[i] != 0) return false;
    return true;
}

bool checkSquareAnagram(int strA, int strB) {
    
    // TODO: Complete checkign if both A and B can be squares
    
    // Brute force
    // 10^numchars
    
}

int main() {
    
    FILE *fin = fopen("p098_words.txt", "r");
    
    for (int i = 0; fscanf(fin, " \" %[^,\"]\", ", words[i]) != EOF; i++) {
        lens[i] = strlen(words[i]);
        wordsByLen[lens[i]].push_back(i);
    }
    
    int count = 0;
    
    for (int l = 1; l < 20; l++) {
        int n = (int)wordsByLen[l].size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int a = wordsByLen[l][i];
                int b = wordsByLen[l][j];
                if (isAnagram(a, b)) {
                    count++;
                    printf("%d %s %s\n", l, words[a], words[b]);
                }
            }
        }
    }
    
    printf("%d\n", count);
    
    fclose(fin);
    return 0;
}