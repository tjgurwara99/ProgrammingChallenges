#include <bits/stdc++.h>
using namespace std;

#define MAXN 70000
#define LEN(arr) ((int)(arr).size())

int A, B;
multiset<string> mSet, iSet;
string mSol, iSol, sol;
int totalLen;

inline bool startsWith(const string& str, const string& prefix) {
    int n = LEN(str), m = LEN(prefix);
    if (m > n) return false;
    for (int i = 0; i < m; i++) {
        if (prefix[i] != str[i]) return false;
    }
    return true;
}

bool solutionSearch() {
    
    // cout << "\ncalled" << endl;
    // cout << mSol << endl << iSol << endl;
    
    int mLen = LEN(mSol), iLen = LEN(iSol);
    
    if (mLen == totalLen || iLen == totalLen) {
        sol = (mLen == totalLen) ? mSol : iSol;
        reverse(sol.begin(), sol.end());
        return true;
    }
    
    if (mLen < iLen) {
        
        string prefix = iSol.substr(mLen);
        prefix += 'I';
        
        int lastPos = 0;
        
        for (int i = 0; i < LEN(prefix)-2; i++) {
            if (prefix[i] == 'A' || prefix[i] == 'M') {
                string append = prefix.substr(lastPos, i-lastPos+1);
                
                auto pos = mSet.find(append);
                if (pos == mSet.end()) return false;
                mSet.erase(pos);
                
                mSol += append;
                lastPos = i+1;
            }
        }
        
        if (lastPos) prefix = prefix.substr(lastPos);
        
        // cout << "PREFIX " << prefix << " " << lastPos << endl;
        
        vector<string> nextValues;
        for (auto it = mSet.lower_bound(prefix); it != mSet.end(); ++it) {
            string next = *it;
            if (!startsWith(next, prefix)) break;
            nextValues.push_back(next);
        }
        
        for (const string& next: nextValues) {
            mSet.erase(mSet.find(next));
            mSol += next;
            
            if (solutionSearch()) return true;
            
            mSol = mSol.erase(mLen);
            mSet.insert(next);
        }
        
    } else {
        
        string prefix = mSol.substr(iLen);
        int lastPos = 0;
        for (int i = 0; i < LEN(prefix)-1; i++) {
            if (prefix[i] == 'I') {
                string append = prefix.substr(lastPos, i-lastPos+1);
                
                auto pos = iSet.find(append);
                if (pos == iSet.end()) return false;
                iSet.erase(pos);
                
                iSol += append;
                lastPos = i+1;
            }
        }
        if (lastPos) prefix = prefix.substr(lastPos);
        
        vector<string> nextValues;
        for (auto it = iSet.lower_bound(prefix); it != iSet.end(); ++it) {
            string next = *it;
            if (!startsWith(next, prefix)) break;
            
            if (LEN(next) <= LEN(prefix)) continue;
            char last = next[LEN(prefix)];
            if (last != 'M' && last != 'A') continue;
            
            nextValues.push_back(next);
        }
        
        for (const string& next: nextValues) {
            iSet.erase(iSet.find(next));
            iSol += next;
            
            if (solutionSearch()) return true;
            
            iSol = iSol.erase(iLen);
            iSet.insert(next);
        }
    }
    
    return false;
}

int main() {
    
    string str;
    
    cin >> A >> B;
    for (int i = 0; i < A; i++) {
        cin >> str;
        reverse(str.begin(), str.end());
        
        if (str[0] != 'M' && str[0] != 'A') {
            mSol = str;
        } else {
            mSet.insert(str);
        }
        
        totalLen += LEN(str);
    }
    for (int i = 0; i < B; i++) {
        cin >> str;
        reverse(str.begin(), str.end());
        if (str[0] != 'I') {
            iSol = str;
        } else {
            iSet.insert(str);
        }
    }
    
    if (!solutionSearch()) cout << "fail" << endl;
    cout << sol << endl;
    
    return 0;
}