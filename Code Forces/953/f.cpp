#include <iostream>
using namespace std;

#define ll long long
#define MAXN 123456

int N, P, M, D[MAXN], T[MAXN];

inline ll nc2(ll x) { return (x*(x+1))>>1; }

int main() {

    cin >> N >> P >> M;
    
    D[0] = 1;
    T[0] = 0;
    for (int i = 1; i <= N; i++) cin >> D[i] >> T[i];
    D[N] = M;
    T[N] = 0;

    ll currentTotal = 0;
    for (int a = 0; a < N; a++) {
        int lower = D[a], upper = D[a+1];



        currentTotal -= P*(ll)(D[a+1]-D[a]);
        currentTotal += T[a+1];
    }

    return 0;
}
