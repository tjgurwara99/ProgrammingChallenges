#include <iostream>
using namespace std;

int main() {
    int num = 1000, sum = 0; 
    for (int i = 3; i < num; i++) {
        if (i % 5 == 0 || i % 3 == 0) sum += i;
    }
    cout << sum << endl;
    return 0;
}
