/* Correct answer in around 2ms */
#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define MAX 80

int A[MAX][MAX];
ll DP[MAX][MAX];

void loadData() {
    FILE* f = fopen("p082_matrix.txt", "r");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) fscanf(f, "%d,", &A[i][j]);
    }
    fclose(f);
}

int main() {

    loadData();

    for (int i = 0; i < MAX; i++) DP[i][0] = A[i][0];

    for (int j = 1; j < MAX; j++) {

        // Left or up
        DP[0][j] = DP[0][j-1] + A[0][j];
        for (int i = 1; i < MAX; i++) DP[i][j] = A[i][j] + min(DP[i][j-1], DP[i-1][j]);

        // Down
        for (int i = MAX-2; i >= 0; i--) DP[i][j] = min(DP[i][j], DP[i+1][j] + A[i][j]);
    }

    ll minEnd = DP[0][MAX-1];
    for (int i = 0; i < MAX; i++) minEnd = min(minEnd, DP[i][MAX-1]);

    printf("%lld\n", minEnd);

    return 0;
}
