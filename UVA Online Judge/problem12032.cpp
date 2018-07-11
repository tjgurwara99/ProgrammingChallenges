#include <iostream>
using namespace std;

int main() {

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, a = 0, b, ans = 0, strength = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> b;
            if (b-a > ans) {
                ans = b-a;
                strength = ans-1;
            } else if (b-a > strength) {
                ans++;
                strength = ans;
            } else if (b-a == strength) {
                strength--;
            }
            a = b;
        }
        cout << "Case " << t << ": " << ans << endl;
    }

    return 0;
}