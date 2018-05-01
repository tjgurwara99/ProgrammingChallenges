#include <cstdio>
#include <array>
using namespace std;
typedef array<double, 40> dist;

dist add(const dist& a, const dist& b) {
    dist result;
    result.fill(0);
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) result[i+j] += a[i]*b[j];
    }
    return result;
}

int main() {
    dist peter, colin;
    peter.fill(0); colin.fill(0);
    
    for (int i = 1; i <= 4; i++) peter[i] = 0.25;
    for (int i = 1; i <= 6; i++) colin[i] = 1/6.0;
    
    dist pRes = peter, cRes = colin;
    for (int i = 0; i < 8; i++) pRes = add(pRes, peter);
    for (int i = 0; i < 5; i++) cRes = add(cRes, colin);
    
    double ans = 0, pSum = 0;
    for (int i = 0; i < 40; i++) {
        pSum += pRes[i];
        ans += cRes[i] * (1 - pSum);
    }
    printf("%.7f\n", ans);
    
    return 0;
}