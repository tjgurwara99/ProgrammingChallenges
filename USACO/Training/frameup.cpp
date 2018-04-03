/*
ID: basimkh1
PROG: frameup
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int W, H;
string frame[50];
bool seen[50], inSolution[50];
int sides[50][4]; // U, D, L, R

inline bool blocked(int y, int x, int c) {
    int d = frame[y][x]-'A';
    if (d < 0 || d >= 26) return false;
    return d != c && !inSolution[d];
}

string solution;
vector<string> solutions;

void findSolution(int charsLeft) {
    
    if (charsLeft == 0) {
        string temp = solution;
        reverse(temp.begin(), temp.end());
        solutions.push_back(temp);
        return;
    }
    
    for (int c = 0; c < 26; c++) {
        if (!seen[c] || inSolution[c]) continue;
        bool isBlocked = false;
        
        for (int h = sides[c][0]; h <= sides[c][1]; h++) {
            isBlocked |= blocked(h, sides[c][2], c);
            isBlocked |= blocked(h, sides[c][3], c);
        }
        for (int w = sides[c][2]; w <= sides[c][3]; w++) {
            isBlocked |= blocked(sides[c][0], w, c);
            isBlocked |= blocked(sides[c][1], w, c);
        }
        
        if (!isBlocked) {
            inSolution[c] = true;
            solution += 'A'+c;
            findSolution(charsLeft-1);
            solution.pop_back();
            inSolution[c] = false;
        }
    }
}

int main() {
    
    freopen("frameup.in", "r", stdin);
    freopen("frameup.out", "w", stdout);
    
    cin >> H >> W;
    
    int numChars = 0;
    
    for (int h = 0; h < H; h++) {
        cin >> frame[h];
        for (int w = 0; w < W; w++) {
            if (frame[h][w] == '.') continue; 
            int idx = frame[h][w] - 'A';
            
            if (!seen[idx]) {
                seen[idx] = true;
                numChars++;
                sides[idx][0] = sides[idx][1] = h;
                sides[idx][2] = sides[idx][3] = w;
            } else {
                sides[idx][1] = h; 
                sides[idx][2] = min(sides[idx][2], w);
                sides[idx][3] = max(sides[idx][3], w);
            }
        }
    }
    
    findSolution(numChars);
    
    sort(solutions.begin(), solutions.end());
    for (string& s: solutions) cout << s << endl;
    
    return 0;
}