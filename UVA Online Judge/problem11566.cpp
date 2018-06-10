#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, X, T, K;
int cost[100], value[100];
int DP[100][1200][23];

int solve(int dim, int budget, int numDishes) {
    if (budget < 0 || numDishes > 2*N) return -100000;
    if (dim == K || numDishes == 2*N) return 0;
    
    int& ans = DP[dim][budget][numDishes];
    if (ans == -1) {
        ans = solve(dim+1, budget, numDishes);
        ans = max(ans,solve(dim+1, budget-cost[dim], numDishes+1) + value[dim]);
        ans = max(ans,solve(dim+1, budget-cost[dim]*2, numDishes+2) + value[dim]*2);
    }
    return ans;
}

int main() {
    while (scanf("%d %d %d %d", &N, &X, &T, &K), N) {
        N++;
        for (int i = 0; i < K; i++) {
            scanf("%d", &cost[i]);
            value[i] = 0;
            for (int j = 0; j < N; j++) {
                int f;
                scanf("%d",&f);
                value[i] += f;
            }
        }
        
        for (int i = 0; i < K; i++) {
            for (int j = 0; j <= X*N; j++) {
                for (int k = 0; k < 2*N; k++) {
                    DP[i][j][k] = -1;
                }
            }
        }
        
        int v = max(0, solve(0, (X*N*10)/11 - N*T, 0));
        printf("%.2f\n", v / (1.0 * N));
    }
    return 0;
}