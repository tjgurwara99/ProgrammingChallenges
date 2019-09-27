#include <iostream>
using namespace std;

const int N = 100000000;
bool isComposite[N+1];
int totient[N+1];

int main() {
  for (int i = 1; i <= N; i++) totient[i] = i;
  for (int i = 2; i <= N; i++) {
    if (isComposite[i]) continue;
    for (int j = i; j <= N; j += i) {
      totient[j] = totient[j]/i*(i-1);
      isComposite[j] = true;
    }
  }
  long long total = 0;
  for (int i = 1; i <= N; i++) total += i-totient[i];
  cout << 6*total << endl;
  return 0;
}
