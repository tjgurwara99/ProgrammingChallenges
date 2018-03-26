#include <bits/stdc++.h>
using namespace std;

pair<int, int> getPos(int level, int pos, bool moveUp) {
    
    if (level == 0) return make_pair(0, 0);
    
    int quadLen =  1 << (level-1);
    int quadCount = quadLen*quadLen;
    
    pair<int, int> res;
    
    if (pos <= quadCount) {
        res = getPos(level-1, pos, false);
    } else if (pos <= 2*quadCount) {
        res = getPos(level-1, pos-quadCount, true);
        res.second += quadLen;
    } else if (pos <= 3*quadCount) {
        res = getPos(level-1, pos-quadCount*2, true);
        res.first += quadLen;
        res.second += quadLen;
    } else {
        res = getPos(level-1, pos-quadCount*3, false);
        res.first = 2*quadLen - res.first;
        res.second = quadLen - res.second;
    }
    
    if (!moveUp) swap(res.first, res.second);
    return res;
}

int main() {
    
    int G, P;
    cin >> G >> P;
    
    pair<int,int> res = getPos(G, P, true);
    cout << res.first <<  " " << res.second << endl;
    
    return 0;
}