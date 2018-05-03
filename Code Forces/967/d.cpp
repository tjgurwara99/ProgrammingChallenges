#include <bits/stdc++.h>
using namespace std;

#define MAXN 400000
#define ll long long

int N, A, B;
pair<int,int> server[MAXN];
int works[2][MAXN];

inline void print(int start, int end) {
    cout << server[start].second;
    for (int i = start+1; i < end; i++) cout << " " << server[i].second;
    cout << "\n";
}

inline int tryValue(int i, int s) {
    if (i > N) return N+1;
    return (int)(upper_bound(works[s]+i, works[s]+N+1, works[s][i-1]) - works[s]);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> A >> B;
    
    for (int i = 1; i <= N; i++) {
        cin >> server[i].first;
        server[i].second = i;
    }
    
    sort(server+1,server+N+1);
    
    for (int i = 1; i <= N; i++) {
        ll a = ((ll)server[i].first) * (N-i+1);
        if (a >= A) works[0][i]++;
        if (a >= B) works[1][i]++;
        works[0][i] += works[0][i-1];
        works[1][i] += works[1][i-1];
    }
    
    bool solved = false;
    
    for (int ignore = 0; ignore < N-1; ignore++) {
        int aCount = ceil(A / (1.0 * server[ignore+1].first));
        int bCount = ceil(B / (1.0 * server[ignore+1].first));
        
        int bIdx = tryValue(ignore+1+aCount, 1);
        int aIdx = tryValue(ignore+1+bCount, 0);
        
        if (bIdx <= N) {
            cout << "Yes\n";
            cout << aCount << " " << (N-bIdx+1) << endl;
            print(ignore+1, ignore+1+aCount);
            print(bIdx, N+1);
            solved = true;
            break;
        }
        
        if (aIdx <= N) {
            cout << "Yes\n";
            cout << (N-aIdx+1) << " " << bCount << endl;
            print(aIdx, N+1);
            print(ignore+1, ignore+1+bCount);
            solved = true;
            break;
        }
    }
    
    if (!solved) {
        cout << "No\n";
    }
    
    return 0;
}