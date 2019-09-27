#include <iostream>
#include <cmath>
using namespace std;

/*
 Suppose a^2 + b^2 = c^2.
 Then a^2 = (b - c)(b + c)

 The number of unique solutions of this is the no. of unique factors of a^2
 where k < a and a^2/k - k is even. 

 If a is even then a = 2^i * b for some i >= 1 and odd b.
 So a^2/k - k is even iff. k is even but not a factor of 2^(2i).
 This happens iff. k = 2^j * d where 1 <= j < 2i and d is a factor of b^2.

 So if we count the factors of b^2 by its prime factor powers product
 and multiply by 2i-1; let this number be P.
 This counts k twice and also counts a itself.
 Thus the number of solutions is (P-1)/2.
 Thus we need P = 2*47547+1 = 95095 = 5*7*11*13*19.

 After some manipulation, the answer for even a is as below.
 A similar process for odd a gives minimal a which is larger so the above is minimal.
 * */

int main() {
  long long a = pow(2LL,10)*pow(3,6)*pow(5,5)*pow(7,3)*pow(11,2);
  cout << a << endl;
  return 0;
}
