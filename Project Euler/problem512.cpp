#include <iostream>
using namespace std;

#define ll long long
#define N 500000000

/* From some analysis 
 * f(n) = 0 if n is even and totient(n) if n is odd
 * thus
 * g(n) = sum of totient(i) for odd i <= n
 *
 * */
bool isComposite[N+1];
int totient[N+1];

int main() {
  for (int i = 1; i <= N; i++) totient[i] = i;
  for (int i = 3; i <= N; i+=2) {
    if (isComposite[i]) continue;
    for (int j = i; j <= N; j += i+i) {
      totient[j] = totient[j]/i*(i-1);
      isComposite[j] = true;
    }
  }
  ll total = 0;
  for (int i = 1; i <= N; i+=2) total += totient[i];
  cout << total << endl;
  return 0;
}
