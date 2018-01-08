#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 60001
#define CHANGE 0.000001

int N, X[MAXN], V[MAXN];

inline double getTime(double startPos) {

    double maxTime = 0;

    for (int i = 0; i < N; i++) {
        double t = abs(X[i]-startPos)/(V[i]*1.0);
        if (t > maxTime) maxTime = t;
    }

    return maxTime;
}

inline bool isIncreasing(double pos) {
    double p2 = pos + CHANGE;
    double maxATime = 0;
    double maxBTime = 0;

    for (int i = 0; i < N; i++) {
        double t1 = abs(X[i]-pos)/(V[i]*1.0);
        double t2 = abs(X[i]-p2)/(V[i]*1.0);

        if (t1 > maxATime) maxATime = t1;
        if (t2 > maxBTime) maxBTime = t2;
    }

    return maxBTime > maxATime;
}

int main() {

    scanf("%d", &N);

    double minPos = 1e10;
    double maxPos = 1;

    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        if (X[i] > maxPos) maxPos = X[i];
        if (X[i] < minPos) minPos = X[i];
    }
    for (int i = 0; i < N; i++) scanf("%d", &V[i]);

    while (maxPos-minPos > CHANGE) {
        double mid = (maxPos+minPos)/2.0;
        bool midInc = isIncreasing(mid);

        if (midInc) maxPos = mid;
        else minPos = mid;
    }

    printf("%f\n", getTime(minPos));

    return 0;
}
