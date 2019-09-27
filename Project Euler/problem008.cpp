#include <iostream>
#include <fstream>
using namespace std;

int arr[1000];

int adjacent13(int num) {
    int max = 0;
    for (int i = 0; i <= num-13; i++) {
        int p = 1;
        for (int j = 0; j < 13; j++) p = p*array[i+j];
        if (p > max) max = p;
    }
    return max;
}

int main() {
    fstream file;
    file.open("p008.txt", ios::in);
    file.seekg(0, file.beg);

    int i = 0;
    while (!file.eof()) {
        char ch;
        file.get(ch);        
        if (ch != '\n') {
            arr[i] = ch-'0';
            i++;
        }
    }
    file.close();
    
    cout << adjacent13(1000) << endl;

    return 0;
}
