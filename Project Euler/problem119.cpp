#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

// Search for numbers up to 10^k where k is the biggest possible
// to avoid overflow in longs
#define K 16
#define M 10000000000000000LL 

inline int digitSum(ll x) {
  int total = 0;
  for (; x; x /= 10) total += x % 10;
  return total;
}

int main() {

  vector<ll> nums;

  for (int i = 2; i <= 9*K; i++) {
    for (ll j = i; j < M; j *= i) {
      if (j >= 10 && digitSum(j) == i) {
        nums.push_back(j);
      }
    }
  }
  
  sort(nums.begin(), nums.end());
  cout << nums[29] << endl;

  return 0;
}
