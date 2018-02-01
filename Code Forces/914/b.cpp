#include <iostream>
using namespace std;

int cardCount[123456];

int main() {
    
    int N, cards[123456];
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
        cardCount[cards[i]]++;
    }
    
    bool conanWins = false;
    
    for (int c = 100000; c >= 1; --c) {
        if (cardCount[c] % 2 == 1) {
            conanWins = true;
            break;
        }
    }
    
    cout << (conanWins ? "Conan" : "Agasa") << endl;
    
    return 0;
}