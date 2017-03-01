/*
ID: basimkh1
PROG: job
LANG: C++11
*/
#include <cstdio>
using namespace std;

#define MAX_M 31

int N, M1, M2;
int A[MAX_M], B[MAX_M];

int main() {
    
    //freopen("job.in", "r", stdin);
    //freopen("job.out", "w", stdout);
    
    scanf("%d %d %d", &N, &M1, &M2);
    
    for (int i = 0; i < M1; i++) scanf("%d", &A[i]);
    for (int i = 0; i < M2; i++) scanf("%d", &B[i]);
    
    /*
    Things to keep track of:
    
    1. Current time
    2. Number of jobs in first queue
    3. Number of jobs done at A, before B
    4. Number of finished jobs (not really needed)
    5. The time left for machine A to finish (0 if empty)
    6. The time left for machine B to finish (0 if empty)
    
    Use a greedy strategy, take the minimum next machine until
    number of finished jobs == N
    
    TWO STEPS:
    
    1. if Check if any of the machines at A are empty
       -> 
    
    */
    
    return 0;
}