#include <iostream>
using namespace std;

int N, M;
pair<int,int> A[20], B[20];
bool canBeShared[2][20][10];
bool oneCanBe[10], twoCanBe[10];

int main() {
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        if (A[i].first > A[i].second) swap(A[i].first, A[i].second);
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i].first >> B[i].second;
        if (B[i].first > B[i].second) swap(B[i].first, B[i].second);
    }
    
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            bool fst = A[i].first == B[j].first || A[i].first == B[j].second;
            bool snd = A[i].second == B[j].first || A[i].second == B[j].second;
            if (fst == snd) continue;
            
            int item = fst ? A[i].first : A[i].second;
            canBeShared[0][i][item] = true;
            canBeShared[1][j][item] = true;
        }
    }
    
    int oneD = 0, twoD = 0;
    
    for (int i = 0; i < N; i++) {
        int a = canBeShared[0][i][A[i].first];
        int b = canBeShared[0][i][A[i].second];
        if (a && b) {
            oneD = 0;
            break;
        }
        if (a || b) {
            oneD++;
            if (a) {
                oneCanBe[A[i].first] = true;
            } else {
                oneCanBe[A[i].second] = true;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        int a = canBeShared[1][i][B[i].first];
        int b = canBeShared[1][i][B[i].second];
        if (a && b) {
            twoD = 0;
            break;
        }
        if (a || b) {
            twoD++;
            if (a) {
                twoCanBe[B[i].first] = true;
            } else {
                twoCanBe[B[i].second] = true;
            }
        }
    }
    
    if (oneD == 0 || twoD == 0) {
        cout << -1 << endl;
    } else {
        int cnt = 0;
        for (int i = 1; i <= 9; i++) {
            if (oneCanBe[i] && twoCanBe[i]) cnt++;
        }
        
        if (cnt > 1) {
            cout << 0 << endl;
        } else {
            for (int i = 1; i <= 9; i++) {
                if (oneCanBe[i] && twoCanBe[i]) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    
    return 0;
}