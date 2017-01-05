/* Correct answer in 150ms */
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

bool numFound[3500];

vector<double> merge(vector<double> a, vector<double> b) {
    vector<double> result;
    for (double& i: a) {
        for (double& j: b) {
            result.push_back(i + j);
            result.push_back(i - j);
            result.push_back(i * j);
            if (j != 0) result.push_back(i / j);
        }
    }
    return result;
}

vector<double> possibleNums(vector<double>& nums) {
    if (nums.size() == 1) return nums;

    vector<double> left, right, acc;
    for (int i = (int)nums.size()-1; i >= 0; i--) right.push_back(nums[i]);

    for (int s = 0; s < (int)nums.size()-1; s++) {
        left.push_back(nums[s]);
        right.pop_back();

        vector<double> vals = merge(possibleNums(left), possibleNums(right));
        acc.insert(acc.end(), vals.begin(), vals.end());
    }

    return acc;
}

inline int consecutiveLength(vector<double> vec) {

    for (int i = 0; i < 3400; i++) numFound[i] = false;
    do {
        for (double x: possibleNums(vec)) {
            if (x > 0 && abs(x-(int)x)==0) numFound[(int)x] = true;
        }
    } while (next_permutation(vec.begin(), vec.end()));

    for (int i = 1;; i++) if (!numFound[i]) return i-1;
}

int main() {

    int maxFound = 0;

    for (int a = 1; a < 7; a++) {
        for (int b = a+1; b < 8; b++) {
            for (int c = b+1; c < 9; c++) {
                for (int d = c+1; d < 10; d++) {
                    int x = consecutiveLength({a*1.0, b*1.0, c*1.0, d*1.0});
                    if (x > maxFound) {
                        maxFound = x;
                        printf("1 to %d: %d%d%d%d\n", x, a, b, c, d);
                    }
                }
            }
        }
    }

    return 0;
}
