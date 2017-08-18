#include <cstdio>
int main() {
    for (int a = 1; a*a*a*a <= 2000000000; ++a) {
        for (int b = a; a*b*b*b <= 2000000000; ++b) {
            for (int c = b; a*b*c*c <= 2000000000; ++c) {
                long long s = a + b + c, p = a * b * c;
                if (p <= 1000000) continue;
                long long d = (s * 1000000) / (p - 1000000);
                if (d >= c && s + d <= 2000 && a+b+c+d == (a*b*c*d)/1000000)  {
                    printf("%.2f %.2f %.2f %.2f\n", a/100.0, b/100.0, c/100.0, d/100.0);
                }
            }
        }
    }
    return 0;
}
