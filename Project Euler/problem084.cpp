/* Correct answer 4.5s */
#include <cstdio>
#include <algorithm>
#include <random>
using namespace std;

#define NUM_STEPS 30000000

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dice(1, 4);
uniform_int_distribution<int> card(1, 16);
int getDiceRoll() { return dice(mt); }
int getCardNum() { return card(mt); }

int freq[40];

int main() {
    
    int pos = 0;
    int numDoubles = 0;
    
    for (int t = 0; t < NUM_STEPS; t++) {
        int d1 = getDiceRoll(), d2 = getDiceRoll();
        if (d1 == d2) numDoubles++;
        else numDoubles = 0;
        
        if (numDoubles == 3) {
            pos = 10;
            numDoubles = 0;
        } else {
            pos += d1 + d2;
            pos %= 40;
            
            /* Community chest */
            if (pos == 2 || pos == 17 || pos == 33) {
                int c = getCardNum();
                if (c == 1) pos = 0;
                if (c == 2) pos = 10;
            }
            
            /* Chance */
            else if (pos == 7 || pos == 22 || pos == 36) {
                int c = getCardNum();
                if (c == 1) pos = 0;
                if (c == 2) pos = 10;
                if (c == 3) pos = 11;
                if (c == 4) pos = 24;
                if (c == 5) pos = 39;
                if (c == 6) pos = 5;
                if (c == 7 || c == 8) {
                    if (pos == 7) pos = 15;
                    if (pos == 22) pos = 25;
                    if (pos == 36) pos = 5;
                }
                if (c == 9) {
                    if (pos == 7) pos = 12;
                    if (pos == 22) pos = 28;
                    if (pos == 36) pos = 12;
                }
                if (c == 10) pos -= 3;
            }
            
            else if (pos == 30) pos = 10;
        }
        
        freq[pos]++;
    }
    
    int fst = 30, snd = 30, thd = 30;
    
    for (int i = 0; i < 40; i++) {
        if (freq[i] > freq[fst]) {
            thd = snd;
            snd = fst;
            fst = i;
        } else if (freq[i] > freq[snd]) {
            thd = snd;
            snd = i;
        } else if (freq[i] > freq[thd]) {
            thd = i;
        }
    }
    
    printf("%d - %f\n", fst, freq[fst] / (NUM_STEPS * 1.0));
    printf("%d - %f\n", snd, freq[snd] / (NUM_STEPS * 1.0));
    printf("%d - %f\n", thd, freq[thd] / (NUM_STEPS * 1.0));
    
    return 0;
}
