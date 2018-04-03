/*
ID: basimkh1
PROG: fc
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 20000

typedef pair<double,double> pnt;

int N;
pnt minPoint, points[MAXN];

inline double angle(const pnt& p) {
    return atan2(p.second - minPoint.second, p.first - minPoint.first);
}

bool compareAngle(const pnt& p1, const pnt& p2) {
    return angle(p1) < angle(p2);
}

inline bool concave(int i, int j, int k) {
    pnt &p1 = points[i], &p2 = points[j], &p3 = points[k];
    
    double v1 = p3.first - p1.first;
    double v2 = p3.second - p1.second;
    
    double x1 = p2.first - p1.first;
    double x2 = p2.second - p1.second;
    
    return (v1*x2-x1*v2) > 1e-8;
}

int main() {
    
    freopen("fc.in", "r", stdin);
    freopen("fc.out", "w", stdout);
    
    cin >> N;
    
    int minIdx = 0;
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
        if (points[i].first < points[minIdx].first) {
            minIdx = i;
        }
    }
    
    if (N < 2) {
        cout << "0.00" << endl;
        return 0;
    }
    
    swap(points[minIdx], points[N-1]);
    minPoint = points[N-1];
    
    sort(points, points+N-1, compareAngle);
    
    vector<int> hullPoints;
    int hullSize = 0;
    
    for (int i = 0; i < N; i++) {
        while (hullSize >= 2 &&
            concave(hullPoints[hullSize-2], hullPoints[hullSize-1], i)) {
            hullPoints.pop_back();
            hullSize--;
        }
        
        hullPoints.push_back(i);
        hullSize++;
    }
    
    double totalDistance = 0;
    
    for (int i = 0; i < hullSize; i++) {
        pnt &a = points[hullPoints[i]], &b = points[hullPoints[(i+1)%hullSize]];
        totalDistance += sqrt(pow(a.first-b.first,2) + pow(a.second-b.second,2));
    }
    
    printf("%.2f\n", totalDistance);
    
    return 0;
}