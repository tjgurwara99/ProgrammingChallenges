#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int F, R, A[20], B[20];

int main() {
    
    while (scanf("%d", &F), F) {
        scanf("%d", &R);
        for (int i = 0; i < F; i++) scanf("%d", &A[i]);
        for (int i = 0; i < R; i++) scanf("%d", &B[i]);
        vector<double> ds;
        for (int i = 0; i < F; i++) {
            for (int j = 0; j < R; j++) {
                ds.push_back(1.0 * A[i] / B[j]);
            }
        }
        sort(ds.begin(), ds.end());
        double maxSpread = ds[1]/ds[0];
        for (int i = 0; i < (int)ds.size()-1; i++) maxSpread = max(maxSpread, ds[i+1]/ds[i]);
        printf("%.2f\n", maxSpread);
    }
    
    return 0;
}