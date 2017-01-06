/* Correct answer in 12s */
#include <cstdio>
using namespace std;

#define MAX 80000
int A[MAX];

int main() {
    
    A[0] = 1;
    for (int i = 1; i < MAX; i++) {
        for (int j = i; j < MAX; j++) {
            A[j] += A[j-i];
            A[j] %= 1000000;
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (!A[i]) printf("%d: %d\n", i, A[i]);
    }

    return 0;
}
