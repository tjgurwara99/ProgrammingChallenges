/*
ID: basimkh1
PROG: lgame
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> dict;
int N;
string input;

int scores[] = { 
    2, 5, 4, 4,
    1, 6, 5, 5,
    1, 7, 6, 3,
    5, 2, 3, 5,
    7, 2, 1, 2,
    4, 6, 6, 7,
    5, 7
};

string word = "";
int spacePos;

inline bool singleWord(const string& str) {
    if (str.empty()) return false;
    auto idx = lower_bound(dict.begin(), dict.end(), str);
    if (idx == dict.end()) return false;
    return *idx == str;
}

inline bool validWord() {
    if (spacePos) {
        return singleWord(word.substr(0, spacePos))
            && singleWord(word.substr(spacePos+1));
    } else {
        return singleWord(word);
    }
}

inline int wordScore() {
    int total = 0;
    for (const char& c: word) {
        if (c != ' ') total += scores[c-'a'];
    }
    return total;
}

bool usedChar[30];
int bestScore = 0;
vector<string> scoreWords;

void search() {
    
    bool valid = validWord();
    
    if (valid) {
        int score = wordScore();
        if (score > bestScore) {
            bestScore = score;
            scoreWords.clear();
        }
        if (score == bestScore) {
            scoreWords.push_back(word);
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (usedChar[i]) continue;
        
        usedChar[i] = true;
        
        if (valid && !spacePos) {
            spacePos = (int)word.size();
            word += ' ';
            word += input[i];
            
            search();
            
            word.pop_back();
            word.pop_back();
            spacePos = 0;
        }
        
        word += input[i];
        search();
        word.pop_back();
        
        usedChar[i] = false;
    }
}

int main() {
    
    freopen("lgame.in", "r", stdin);
    freopen("lgame.out", "w", stdout);
    
    ifstream dictionary("lgame.dict");
    string temp;
    while (dictionary >> temp, temp != ".") {
        dict.push_back(temp);
    }
    dictionary.close();
    
    cin >> input;
    N = (int)input.size();
    
    search();
    set<string> words;
    for (string s: scoreWords) {
        auto sp = s.find(" ");
        if (sp != string::npos) {
            string a1 = s.substr(0, sp);
            string a2 = s.substr(sp+1);
            string a = (a1 < a2) ? (a1+" "+a2) : (a2+" "+a1);
            
            words.insert(a);
        } else {
            words.insert(s);
        }
    }
    
    cout << bestScore << endl;
    for (string s: words) {
        cout << s << endl;
    }
    
    return 0;
}