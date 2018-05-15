/*
ID: basimkh1
PROG: charrec
LANG: C++11
*/
#include <cstdio>
#include <cassert>
#include <utility>
#include <vector>
using namespace std;

#define FONT_FILE "font.in"
#define pss pair<pair<short, short>,short>

int N;
char lines[1300][30];

char characters[] = " abcdefghijklmnopqrstuvwxyz";
char fontLines[27][30][30];
pss DP[2][27][21][2];
vector<pair<char,short> > stringCache(1);

short addCache(short current, char newChar) {
    stringCache.push_back(make_pair(newChar, current));
    return (short)stringCache.size()-1;
}

void printCache(short current) {
    if (current == 0) printf("\n");
    else {
        printf("%c", stringCache[current].first);
        printCache(stringCache[current].second);
    }
}

inline pss& minPair(pss& a, pss& b) return (a.first.first < b.first.first) ? a : b;

void iterDP() {
    for (int c = 0; c < 27; c++) {
        for (int cLn = 0; cLn < 20; cLn++) {
            DP[N&1][c][cLn][0].first.first = 20000;
            DP[N&1][c][cLn][1].first.first = 20000;
        }
    }
    
    for (int ln = N-1; ln >= 0; --ln) {
        int bestChar = 0;
        auto& curr = DP[ln&1];
        auto& prev = DP[1-(ln&1)];
        for (int c = 0; c < 27; c++) {
            for (int cLn = 0; cLn < 20; cLn++) {
                int diff = 0;
                for (int i = 0; i < 20; i++) {
                    if (lines[ln][i] != fontLines[c][cLn][i]) ++diff;
                }
                
                // use a line
                for (int i = 0; i < 2; i++) {
                    curr[c][cLn][i] = prev[c][cLn+1][i];
                    curr[c][cLn][i].first.first += diff;
                    curr[c][cLn][i].first.second += diff;
                }
                
                // duplicates
                curr[c][cLn][0] = minPair(curr[c][cLn][0], prev[c][cLn][1]);
            }
            
            // missing line (for zero only)
            curr[c][0][0] = minPair(curr[c][0][0], curr[c][1][1]);
            // best character from position
            if (curr[c][0][0].first.first < curr[bestChar][0][0].first.first) {
                bestChar = c;
            }
        }
        
        // next best
        pair<pair<short,short>, short > bestRes = curr[bestChar][0][0];
        char nextChar = bestRes.first.second > 120 ? '?' : characters[bestChar];
        bestRes.second = addCache(bestRes.second, nextChar);
        bestRes.first.second = 0;
        for (int c = 0; c < 27; c++) curr[c][20][0] = curr[c][20][1] = bestRes;
        
        // missing line for all
        for (int c = 0; c < 27; c++) {
            for (int cLn = 0; cLn < 20; cLn++) {
                curr[c][cLn][0] = minPair(curr[c][cLn][0], curr[c][cLn+1][1]);
            }
        }
    }
}

void readFontFile() {
    FILE *fin = fopen(FONT_FILE, "r");
    
    int charCount;
    fscanf(fin, "%d", &charCount);
    charCount /= 20;
    assert(charCount == 27);
    
    for (int c = 0; c < 27; c++) {
        for (int i = 0; i < 20; i++) {
            fscanf(fin, " %s", fontLines[c][i]);
        }
    }
    
    fclose(fin);
}

int main() {
    
    freopen("charrec.in", "r", stdin); freopen("charrec.out", "w", stdout);
    
    readFontFile();
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf(" %s", lines[i]);
    
    iterDP();
    printCache(DP[0][0][20][0].second);
    
    return 0;
}