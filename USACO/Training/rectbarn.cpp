/*
ID: basimkh1
PROG: rectbarn
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define FOR(i,a,b) for (int (i) = (a); i < (b); i++)

ifstream fin("rectbarn.in");
ofstream fout("rectbarn.out");

int R, C, P;
bool blocked[3000][3000];
int rowSize[3001];

int main() {

    fin >> R >> C >> P;

    for (int i = 0; i < P; i++) {
        int r, c;
        fin >> r >> c;
        blocked[r-1][c-1] = true;
    }

    int width = 0, bestArea = 0;
    vector<pair<int, int> > xs;

    for (int c = C-1; c >= 0; c--) {
        for (int r = 0; r < R; r++) {
            rowSize[r] = blocked[r][c] ? 0 : (rowSize[r] + 1);
        }
        width = 0;
        for (int r = 0; r <= R; r++) {
            if (rowSize[r] > width) {
                xs.push_back(make_pair(r, rowSize[r]));
                width = rowSize[r];
            }
            if (rowSize[r] < width) {
                int lastR = r;
                while (rowSize[r] < width) {
                    lastR = xs[xs.size()-1].first;
                    bestArea = max(bestArea, (r - lastR) * width);
                    xs.pop_back();
                    width = xs.empty() ? 0 : xs[xs.size()-1].second;
                }
                if (rowSize[r]) {
                    xs.push_back(make_pair(lastR, rowSize[r]));
                    width = rowSize[r];
                }
            }
        }
    }

    fout << bestArea << endl;

    fin.close();
    fout.close();

    return 0;
}