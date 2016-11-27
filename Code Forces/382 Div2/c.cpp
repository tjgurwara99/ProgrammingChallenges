#include <iostream>
#include <cassert>
using namespace std;

#define ll long long
#define MAXROUNDS 100000
ll played[MAXROUNDS], N, numLeft;

int main() {

    cin >> N;

    played[0] = N-1;
    numLeft = N;
    int winner = 0;

    while (true) {
        if (played[winner] > 0) {
            played[winner]--;
            numLeft--;
            winner++;

        } else if (winner > 0 && played[winner-1] > 0) {
            played[winner-1]--;
            numLeft--;
            winner++;

        } else {
            ll pNumLeft = numLeft;
            for (int r = 1; r < winner; r++) {

                if (played[r-1] == 1) {
                    assert(played[r] > 0);
                    played[r-1] = 0;
                    played[r]--;
                    played[r+1]++;
                    numLeft--;
                }

                ll change = played[r-1] >> 1;
                played[r-1] -= change << 1;
                played[r] += change;
                numLeft -= change;

                if (r > 1 && played[r-1] == 1 && played[r-2] == 1) {
                    played[r-1] = played[r-2] = 0;
                    played[r]++;
                    numLeft--;
                }
            }

            if (pNumLeft == numLeft) break;
        }
    }

    cout << winner << endl;

    return 0;
}
