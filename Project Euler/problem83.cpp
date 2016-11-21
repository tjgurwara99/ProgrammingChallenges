#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define MAX 5

int A[MAX][MAX];
ll DP[MAX][MAX];

void loadData() {
    FILE* f = fopen("p082_test.txt", "r");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) fscanf(f, "%d,", &A[i][j]);
    }
    fclose(f);
}

void downPass() {
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            DP[i][j] = A[i][j] + min(DP[i-1][j], DP[i][j-1]);
        }
    }
}

void upPass() {
    for (int i = MAX-2; i >= 0; i--) {
        for (int j = MAX-2; j >= 0; j--) {
            DP[i][j] = min(DP[i][j], A[i][j] + min(DP[i+1][j], DP[i][j+1]));
        }
    }
}

int main() {
    
    loadData();
    
    DP[0][0] = A[0][0];
    for (int i = 1; i < MAX; i++) {
        DP[0][i] = DP[0][i-1] + A[0][i];
        DP[i][0] = DP[i-1][0] + A[i][0];
    }
    
    downPass();
    upPass();
    downPass();
    upPass();
    downPass();
    upPass();
    downPass();
    upPass();
    downPass();
    
    printf("%lld\n", DP[MAX-1][MAX-1]);
    
    return 0;
}