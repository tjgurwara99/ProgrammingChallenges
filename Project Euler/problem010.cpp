#include <iostream>
using namespace std;

#define N 2000000

bool isComposite[N];

int main() {
    long long sum = 0;
    for (int i = 2; i < N; i++) {
      if (isComposite[i]) continue;
      sum += i;
      for (int j = i; j < N; j+=i) isComposite[j] = true;
    }
    cout << sum << endl;
    return 0;
}
