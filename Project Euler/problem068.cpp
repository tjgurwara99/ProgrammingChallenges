/* Correct solution in 21ms */
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int numsUsed[10];
string maxFound = "0000000000000000";

void checkCombination() {

    int pSum = numsUsed[0] + numsUsed[1] + numsUsed[2];
    for (int i = 0; i < 10; i += 2) if (numsUsed[i] + numsUsed[i+1] + numsUsed[(i+2)%10] != pSum) return;
    
    vector<string> partStrings;
    for (int i = 0; i < 10; i += 2) {
        partStrings.push_back(to_string(numsUsed[i+1]) + to_string(numsUsed[i]) + to_string(numsUsed[(i+2)%10]));
    }

    int minIndex = 0;
    for (int i = 0; i < 5; i++) {
        if (partStrings[i].size() == 4) continue;
        if (partStrings[i].size() < partStrings[minIndex].size() || partStrings[i][0] < partStrings[minIndex][0]) minIndex = i;
    }

    string res = "";
    for (int i = 0; i < 5; i++) res += partStrings[(minIndex + i) % 5];

    if (res.size() == 16 && res > maxFound) maxFound = res;
}

void genAll(int index) {

    if (index == 10) {
        checkCombination();
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (numsUsed[i] != -1) continue;

        numsUsed[i] = index;
        genAll(index+1);
        numsUsed[i] = -1;
    }

} 

int main() {

    for (int i = 0; i < 10; i++) numsUsed[i] = -1;
    numsUsed[9] = 10; // Fix 10 since it must be outside

    genAll(1);
    printf("%s\n", maxFound.c_str());

    return 0;
}
