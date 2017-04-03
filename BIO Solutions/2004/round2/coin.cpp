#include <cstdio>

bool coins[100000];
bool tempCoins[100000];
int n;

inline bool allHeads() {
    for (int i = 0; i < n; i++) if (coins[i]) return false;
    return true;
}

int doIt() {
    int moves = 0;
    while (!allHeads()) {
        int sz = (moves % n)+1;
        for (int i = 0; 2*i < sz; i++) {
            bool temp = coins[i];
            coins[i] = !coins[sz-1-i];
            coins[sz-1-i] = !temp;
        }
        moves++;
    }
    return moves;
}

int doItFaster() {

    int moves = 0;
    bool done = false;

    while (!done) {

        bool alternating = true;
        bool nextNeeded = false; // heads at end

        for (int i = n-1; i >= 0; --i) {
            if (coins[i] != nextNeeded) {
                alternating = false;
                break;
            }
            nextNeeded = !nextNeeded;
        }

        if (alternating) {
            moves += doIt();
            break;
        }

        int lastIdx = 0;
        for (int i = 0; 2*i < n; i++) {
            tempCoins[lastIdx++] = !coins[n-1-2*i];
        }
        for (int i = 0; 2*(i+1) <= n; i++) {
            tempCoins[lastIdx++] = coins[2*i + (n & 1)];
        }

        done = true;
        for (int i = 0; i < n; i++) {
            coins[i] = tempCoins[i];
            if (coins[i]) done = false;
        }
        moves += n;
    }

    return moves;
}

int main() {
    scanf("%d", &n);
    printf("%d\n", doItFaster());
    return 0;
}
