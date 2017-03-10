#include <iostream>
using namespace std;

int ac[10];
int bc[10];
bool pickedA[10];
bool pickedB[10];

inline bool isValid() {
    
    for (int i = 1; i < 10; i++) {
        int fd = (i*i)/10;
        int sd = (i*i)%10;
        
        if (!((ac[fd] && bc[sd]) || (bc[fd] && ac[sd]))) return false;
    }
    
    return true;
}

int count = 0;

void searchB(int idx, int j) {
    if (idx == 6) {
        if (isValid()) count++;
        return;
    }
    
    for (int i = j; i < 10; i++) {
        if (!pickedB[i]) {
            pickedB[i] = true;
            if (i == 6) bc[9]++;
            if (i == 9) bc[6]++;
            bc[i]++;
            searchB(idx+1, i+1);
            bc[i]--;
            if (i == 6) bc[9]--;
            if (i == 9) bc[6]--;
            pickedB[i] = false;
        }
    }
}

void searchA(int idx, int j) {
    
    if (idx == 6) {
        searchB(0, 0);
        return;
    }
    
    for (int i = j; i < 10; i++) {
        if (!pickedA[i]) {
            pickedA[i] = true;
            if (i == 6) ac[9]++;
            if (i == 9) ac[6]++;
            ac[i]++;
            searchA(idx+1, i+1);
            ac[i]--;
            if (i == 6) ac[9]--;
            if (i == 9) ac[6]--;
            pickedA[i] = false;
        }
    }
}

int main() {
    searchA(0, 0);
    cout << count << endl;
    return 0;
}