#include <iostream>
#include <algorithm>
using namespace std;

int N, M1, M2, A[30], B[30];
int aTimes[1000], bTimes[1000], nextFinish[30];

int main() {
    cin >> N >> M1;
    for (int i = 0; i < M1; i++) cin >> A[i];
    cin >> M2;
    for (int i = 0; i < M2; i++) cin >> B[i];
    
    for (int i = 0; i < M1; i++) nextFinish[i] = A[i];
    for (int i = 0; i < N; i++) {
        int j = (int)(min_element(nextFinish, nextFinish+M1) - nextFinish);
        aTimes[i] = nextFinish[j];
        nextFinish[j] += A[j];
    }
    
    for (int i = 0; i < M2; i++) nextFinish[i] = B[i];
    for (int i = 0; i < N; i++) {
        int j = (int)(min_element(nextFinish, nextFinish+M2) - nextFinish);
        bTimes[i] = nextFinish[j];
        nextFinish[j] += B[j];
    }
    
    int maxTime = 0;
    for (int i = 0; i < N; i++)  maxTime = max(maxTime, aTimes[i] + bTimes[N-i-1]);
    
    cout << aTimes[N-1] << endl << maxTime << endl;
    
    return 0;
}