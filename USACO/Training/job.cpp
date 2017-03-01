/*
ID: basimkh1
PROG: job
LANG: C++11
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 1005
#define MAX_M 32

int N, M1, M2;
int machineA[MAX_M], machineB[MAX_M];
int aFinishTime[MAX_N], bFinishTime[MAX_N];
int timeA[MAX_M], timeB[MAX_M];

int main() {

    freopen("job.in", "r", stdin);
    freopen("job.out", "w", stdout);

    scanf("%d %d %d", &N, &M1, &M2);

    for (int i = 0; i < M1; i++) scanf("%d", &machineA[i]);
    for (int i = 0; i < M2; i++) scanf("%d", &machineB[i]);

    int totalATime = 0, totalTime = 0;

    for (int i = 0; i < N; i++) {
        int minT = 100000, minIdx = -1;
        for (int j = 0; j < M1; j++) {
            if (timeA[j] + machineA[j] < minT) {
                minT = timeA[j] + machineA[j];
                minIdx = j;
            }
        }
        aFinishTime[i] = minT;
        timeA[minIdx] += machineA[minIdx];
        totalATime = timeA[minIdx];
    }

    for (int i = N-1; i >= 0; i--) {
        int minT = 100000, minIdx = -1;
        for (int j = 0; j < M2; j++) {
            if (timeB[j] + machineB[j] < minT) {
                minT = timeB[j] + machineB[j];
                minIdx = j;
            }
        }
        bFinishTime[i] = minT;
        timeB[minIdx] += machineB[minIdx];
    }

    for (int i = 0; i < N; i++) totalTime = max(totalTime, aFinishTime[i]+bFinishTime[i]);
    printf("%d %d\n", totalATime, totalTime);

    return 0;
}
