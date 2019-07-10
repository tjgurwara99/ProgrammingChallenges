#include <iostream>
#include <math.h>
using namespace std;

/* I am using a mathematically proved formula of pythagorean triplet formula

  a = m^2 - n^2
  b = 2mn
  c = m^2 + n^2
    
  we are given that a + b + c = 1000
  using m and n relationship here
  I came up with this
  2m^2 + 2mn = 1000
  using some mathematics
  m^2 + mn - 500 = 0
  so m = (-n +- sqrt(n^2 + 2000))/2

  i will only be using the positive formula because we want the value of m to be positive
  finally abc = (m^4 - n^4)(2mn)
  
  you can find a lot of different ways to get pythagorian triplets online and create a different algorithm
  I found this one to be the fastest in my machine, faster than even the first program :P (I have no idea why though)
*/  

bool isInteger(float num) { return (int)num == num; }

int main() {
    int n = 1;
    float m;
    do {
        n++;
        float sq = n*n + 2000;
        m = (sqrt(sq)-n)/2;
    } while (!isInteger(m));
    int ans = (m*m*m*m - n*n*n*n)*2*m*n;
    cout << ans << endl;
    return 0;
}
