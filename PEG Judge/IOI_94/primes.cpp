#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAXP 100000
#define MAXC 5000

bool isComposite[MAXP];
short nodeChild[MAXC][10], nodeMask[MAXC], trieCount = 1;
int LOG2[1<<10];

inline int digitSum(int n) {
    int a = 0;
    for (; n; n /= 10) a += n%10;
    return a;
}

inline int revDigits(int n) {
    int a = 0;
    for (; n; n /= 10) a = a*10 + n%10;
    return a;
}

void addTrie(int n) {
    for (int node = 0; n; n /= 10) {
        int k = n % 10;
        if (!nodeChild[node][k]) nodeChild[node][k] = trieCount++;
        nodeMask[node] |= (1 << k);
        node = nodeChild[node][k];
    }
}

int rowNode[5], colNode[5], diagNode, revDiag, gridValues[5][5];
bool foundSolution = false;
int s;

vector<string> solutions;

void search(int r, int c) {
    
    if (c == 5) {
        string sol(30, '\n');
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) sol[i*6+j] = gridValues[i][j]+'0';
        }
        foundSolution = true;
        solutions.push_back(sol);
        return;
    }
    
    if (r == 5) {
        search(0, c+1);
        return;
    }
    
    int oldR = rowNode[r], oldC = colNode[c], oldDiag = diagNode, oldRev = revDiag;
    
    short digitMask = nodeMask[oldR] & nodeMask[oldC];
    if (r == c) digitMask &= nodeMask[oldDiag];
    if (r+c == 4) digitMask &= nodeMask[oldRev];
    
    while (digitMask) {
        int k = digitMask & (-digitMask);
        int d = LOG2[k];
        digitMask -= k;
        
        rowNode[r] = nodeChild[oldR][d];
        colNode[c] = nodeChild[oldC][d];
        if (r == c) diagNode = nodeChild[oldDiag][d];
        if (r+c == 4) revDiag = nodeChild[oldRev][d];
        gridValues[r][c] = d;
        search(r+1, c);
        rowNode[r] = oldR;
        colNode[c] = oldC;
        diagNode = oldDiag;
        revDiag = oldRev;
    }
}

int main() {
    
    for (int i = 0; i < 10; i++) LOG2[1 << i] = i;
    
    isComposite[0] = isComposite[1] = true;
    for (int i = 2; i*i < MAXP; i++) {
        if (isComposite[i]) continue;
        for (int j = i*i; j < MAXP; j += i) isComposite[j] = true;
    }
    
    scanf("%d %d", &s, &gridValues[0][0]);
    
    for (int i = 10001; i < 100000; i+=2) {
        if (!isComposite[i] && digitSum(i) == s) addTrie(revDigits(i));
    }
    
    rowNode[0] = colNode[0] = diagNode = nodeChild[0][gridValues[0][0]];
    if (!rowNode[0]) {
        printf("NONE\n");
        return 0;
    }
    search(1, 0);
    if (!foundSolution) {
        printf("NONE\n");
    } else {
        sort(solutions.begin(), solutions.end());
        bool first = true;
        for (string& s: solutions) {
            if (!first) printf("\n");
            printf("%s", s.c_str());
            first = false;
        }
    }
    
    return 0;
}