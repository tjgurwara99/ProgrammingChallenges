#include <cstdio>
#include <cmath>

int p,q,r,s,t,u;

inline double f(double x) { return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u; }

int main() {
    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        if (f(0)<0 || f(1)>0) {
            printf("No solution\n");
            continue;
        }
        double l=0,h=1;
        for (int i = 0; i < 30; i++) {
            double m = (l+h)/2;
            if (f(m)<0) h=m;
            else l=m;
        }
        printf("%.4f\n",l);
    }
    return 0;
}