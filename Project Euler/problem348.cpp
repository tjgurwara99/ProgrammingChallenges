#include <iostream>
#include <map>
using namespace std;

#define MAX 1000000000

inline bool isPalindrome(int n) {
  int x = 0;
  for (int i = n; i; i /= 10) x = x*10+(i%10);
  return x == n;
}

char cnt[MAX];

int main() {

  for (int i = 2; i*i < MAX; i++) {
    for (int j = 2;; j++) {
      int x = i*i+j*j*j;
      if (x >= MAX) break;
      cnt[x]++;
    }
  }

  long long ans = 0;
  int needed = 5;
  for (int i = 0; i < MAX; i++) {
    if (cnt[i] == 4 && isPalindrome(i)) {
      ans += i;
      if (--needed == 0) break;
    }
  }
  cout << ans << endl;

  return 0;
}
