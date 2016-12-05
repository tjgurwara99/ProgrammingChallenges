#include <cstdio>
#include <cmath>
#include <cstdio>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string letterWords[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

inline array<int,26> toLetterCount(int n) {
    array<int,26> count;
    fill(count.begin(), count.end(), 0);
    
    for (; n; n /= 10) {
        for (char c: letterWords[n % 10]) count[c-'A']++;
    }
    
    return count;
}

array<int,26> allCounts[1000];
vector<int> connections[1000];

bool isSimilar(int a, int b) {
    int diff = 0;
    for (int i = 0; i < 26; i++) {
        diff += abs(allCounts[a][i] - allCounts[b][i]);
    }
    return diff <= 5;
}

void countAll() {
    for (int i = 1; i < 1000; i++) allCounts[i] = toLetterCount(i);
    
    for (int i = 1; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            if (isSimilar(i, j)) {
                connections[i].push_back(j);
                connections[j].push_back(i);
            }
        }
    }
}

int dist[1000];

inline int minLadder(int s, int f) {
    
    fill(dist, dist+1000, 10000);
    
    dist[s] = 0;
    
    while (dist[f] == 10000) {
        for (int i = 1; i < 1000; i++) {
            if (dist[i] == 10000) continue;
            for (int j: connections[i]) {
                if (dist[j] <= dist[i]) continue;
                dist[j] = dist[i]+1;
            }
        }
    }
    
    return dist[f];
}

int main() {
    
    countAll();
    int input[3][2];
    
    for (int i = 0; i < 3; i++) scanf("%d %d", &input[i][0], &input[i][1]);
    for (int i = 0; i < 3; i++) printf("%d\n", minLadder(input[i][0], input[i][1]));
    
    return 0;
}