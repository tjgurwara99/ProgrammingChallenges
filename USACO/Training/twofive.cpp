/*
ID: basimkh1
PROG: twofive
LANG: C++11
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int DP[10][10][10][10][10], heights[10], x[25], y[25];
bool used[25];

int countGrid() {
    int charNum = 0;
    for (int i = 0; i < 5; i++) charNum += heights[i];

    if (charNum == 25) return 1;
    int& ans = DP[heights[0]][heights[1]][heights[2]][heights[3]][heights[4]];
    if (ans < 0) {
        ans = 0;
        if (!used[charNum]) {
            for (int i = 0; i < 5; i++) {
                if (heights[i] != 5 && (!i || heights[i] < heights[i-1])) {
                    heights[i]++;
                    ans += countGrid();
                    heights[i]--;
                }
            }
        } else if (heights[x[charNum]] == y[charNum] && (!x[charNum] || heights[x[charNum]] < heights[x[charNum]-1])) {
            heights[x[charNum]]++;
            ans += countGrid();
            heights[x[charNum]]--;
        }
    }
    return ans;
}

int countNumGrids() {
    for (int i = 0; i < 5; i++) heights[i] = 0;
    memset(DP, -1, sizeof(DP));
    return countGrid();
}

string nthString(int n) {

    for (int i = 0; i < 25; i++) used[i] = false;

    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 5; i++) {
            for (int c = 0; c < 25; c++) {
                if (used[c]) continue;
                x[c] = i;
                y[c] = j;
                used[c] = true;
                int cnt = countNumGrids();
                if (cnt > n) break;
                n -= cnt;
                used[c] = false;
            }
        }
    }

    string S(25, ' ');
    for (int i = 0; i < 25; i++) S[x[i] + y[i]*5] = 'A'+i;
    return S;
}

int stringIdx(string s) {
    int l = 0, h = 701149020;
    while ((h - l) > 1) {
        int m = (l+h)/2;
        string sm = nthString(m);
        if (sm < s)         l = m+1;
        else if (sm > s)    h = m;
        else                return m;
    }
    return l;
}

int main() {

    freopen("twofive.in", "r", stdin);
    freopen("twofive.out", "w", stdout);

    char c;
    cin >> c;

    if (c == 'N') {
        int idx;
        cin >> idx;
        cout << nthString(idx-1) << endl;
    } else {
        string str;
        cin >> str;
        cout << 1+stringIdx(str) << endl;
    }

    return 0;
}