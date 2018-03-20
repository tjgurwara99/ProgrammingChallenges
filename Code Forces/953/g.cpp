#include <iostream>
using namespace std;

int N, cnt[2], a;

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        cnt[a%2]++;
    }

    cout << min(cnt[0], cnt[1]) << endl;

    return 0;
}
