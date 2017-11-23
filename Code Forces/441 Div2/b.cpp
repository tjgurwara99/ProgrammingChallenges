#include <iostream>
#include <vector>
using namespace std;

#define MAX 200000
int N, K, M, A[MAX];
vector<int> modCounts[MAX];

int main() {
    
    cin >> N >> K >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        modCounts[A[i] % M].push_back(A[i]);
    }
    
    for (int i = 0; i < M; i++) {
        if ((int)modCounts[i].size() >= K) {
            cout << "Yes" << endl;
            for (int j = 0; j < K; j++) cout << modCounts[i][j] << " ";
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}