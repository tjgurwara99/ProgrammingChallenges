/*
ID: basimkh1
PROG: shuttle
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> moves;

void move(string& str, int& spacePos, bool left) {
    int dir = left ? -1 : 1;
    char next = left ? 'W' : 'B';
    
    if (str[spacePos+dir] == next) {
        moves.push_back(spacePos+dir);
        swap(str[spacePos+dir], str[spacePos]);
        spacePos += dir;
    } else {
        moves.push_back(spacePos+dir*2);
        swap(str[spacePos+dir*2], str[spacePos]);
        spacePos += dir*2;
    }
}

void moveTo(int N, string& str, int& spacePos, int offset) {
    bool moveLeft = spacePos > (N+offset);
    while (spacePos != (N+offset)) move(str, spacePos, moveLeft);
}

int main() {
    
    freopen("shuttle.in", "r", stdin);
    freopen("shuttle.out", "w", stdout);
    
    int N;
    cin >> N;
    
    string str = string(N,'W')+" "+string(N,'B');
    int spacePos = N;
    
    for (int i = 0; i <= N; i++) moveTo(N, str, spacePos, (i % 2) ? -i : i);
    for (int i = N; i >= 0; i--) moveTo(N, str, spacePos, (i % 2) ? i : -i);
    
    bool first = true;
    for (int i = 0; i < (int)moves.size(); i++) {
        if (!first) cout << " ";
        cout << moves[i]+1;
        first = false;
        if (i % 20 == 19) {
            cout << endl;
            first = true;
        }
    }
    if (!first) cout << endl;
    
    return 0;
}