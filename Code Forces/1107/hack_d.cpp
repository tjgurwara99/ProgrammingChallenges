#include <cstdlib>

#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <string>
#include <algorithm>
#include <unordered_map>
 
#define MAXN 1000007
#define MAXM 300007
#define MAXL 500007

#define MAXN_LOG 25
#define FILE "input.txt"
#define M_PI           3.14159265358979323846
 
using namespace std; 

int n, k;

int mt[5207][5207];
int dp[5207][5207];

int chr[300];

int nt[5400];

int check(int x) {
	for(int i = x;i <= n;i += x)
		for(int o = x;o <= n;o += x)
			if(dp[i][o] < x)
				return 0;
	return 1;
}
int main() {
	//freopen("input.txt", "r", stdin);
	
	//freopen("taxi.in", "r", stdin);
	//freopen("taxi.out", "w", stdout);
	
	//cout.precision(20);
	
	for(int i = '0';i <= '9';i++)
		chr[i] = i;
	for(int i = 'A';i <= 'F';i++)
		chr[i] = 10 + i - 'A';
		
	
	ios_base::sync_with_stdio(false);
	cin >> n;
	char c;
	for(int i = 1;i <= n;i++) {
		for(int o = 1;o <= n / 4;o++) {
			cin >> c;
			for(int k = 1;k <= 4;k++)
				mt[i][(o - 1) * 4 + k] = ((chr[c] & (1 << (4 - k))) ? 1 : 0);
		}
	}
	/*
	for(int i = 1;i <= n;i++) {
		for(int o = 1;o <= n;o++)
			cout << mt[i][o];
		cout << endl;
	}
	*/
	for(int i = 1;i <= n;i++)
		for(int o = 1;o <= n;o++)
			if(mt[i][o] == mt[i][o - 1] && mt[i][o] == mt[i - 1][o] && mt[i][o] == mt[i - 1][o - 1])
				dp[i][o] = 1 + min(dp[i - 1][o], min(dp[i][o - 1], dp[i - 1][o - 1]));
			else
				dp[i][o] = 1;
		
	int res = 1;
	for(int i = 2;i <= n;i++)
		if(n % i == 0) {
			if(nt[i] == 0) {
				if(check(i))
					res = i;
				else
					for(int o = i;o <= n;o += i)
						nt[i] = 1;
			}
			
		}
	cout << res << endl;	
	return 0;
}