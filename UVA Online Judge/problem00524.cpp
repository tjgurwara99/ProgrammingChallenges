#include <cstdio>

int N, nums[20];
bool used[20], isComposite[50];
    
void solve(int pos) {
    if (pos == N) {
        if (isComposite[nums[N-1] + nums[0]]) return;
        printf("%d", nums[0]);
        for (int i = 1; i < N; i++) printf(" %d", nums[i]);
        printf("\n");
        return;
    }
    for (int i = 2; i <= N; i++) {
        if (used[i]) continue;
        if (isComposite[nums[pos-1]+i]) continue;
        used[i] = true;
        nums[pos] = i;
        solve(pos+1);
        used[i] = false;
    }
}

int main() {
    
    isComposite[0] = isComposite[1] = true;
    for (int i = 2; i < 50; i++) {
        if (isComposite[i]) continue;
        for (int j = i*i; j < 50; j += i) isComposite[j] = true;
    }
    
    int t = 0;
    while (scanf("%d", &N) != EOF) {
        if (t) printf("\n");
        printf("Case %d:\n", ++t);
        nums[0] = 1;
        solve(1);
    }
    
    return 0;
}