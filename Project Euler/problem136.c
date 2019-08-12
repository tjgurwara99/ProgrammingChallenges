/* Solved via sieving for solutions by noticing that
 * the solutions have a one-to-one correspondence with
 * factor pairs of p*q=n where p+q mod 4 == 0 and either
 * 3p-q or 3q-p is positive.
 * (derivation via straight forward algebra)
 *
 * Solves in ~1.3s (could be made faster by optimising wasted multiplications)
 * */
#include <stdio.h>
#define N 50000000
int sols[N];
int main() {
  int p, q, i, ans;
  for (p = 1; p*p < N; p++) {
    q = p;
    while ((p + q) % 4) q++;
    for (; p*q < N; q+=4) {
      if (3*p-q > 0) sols[p*q]++;
      if (p != q && 3*q-p > 0) sols[p*q]++; // Avoid double counting p==q case
    }
  }
  ans = 0;
  for (i = 1; i < N; i++) if (sols[i] == 1) ans++;
  printf("%d\n", ans);
  return 0;
}
