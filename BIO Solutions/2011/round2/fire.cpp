#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000

int DP[1000][1000];

/*
 * Returns minimum fired sum for employees with id's more
 * than or equal to idx
 * */
int solve(int idx, int sum) {
    /* Base cases */
    if (sum == 0) return 0;
    if (idx > sum) return INF;
    if (idx == sum) return idx;

    /* DP Case */
    if (DP[idx][sum]) return DP[idx][sum];

    /* Recursive case */
    DP[idx][sum] = solve(idx+1, sum);
    for (int i = idx, runningSum=idx; runningSum <= sum; i++, runningSum+=i) {
        int a = solve(i+2, sum-runningSum)+idx+i;
        if (i == idx) a -= i;
        if (a < DP[idx][sum]) DP[idx][sum] = a;
    }

    return DP[idx][sum];
}

int main() {
    int s;
    scanf("%d", &s);
    printf("%d\n", solve(0, s));
    return 0;
}
