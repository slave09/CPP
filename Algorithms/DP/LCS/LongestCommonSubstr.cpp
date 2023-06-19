/*
	# Longest Common Substring
	* We have to break where dissimilar element is encountered unlike Longest Common Subsequence (Line 21 in code)
	* Length of the substrings are stored in the dp
	* we've to calculate max length at every step to get longest common substring
*/


#include<bits/stdc++.h>
using namespace std;

int getLongestSubstr(string &a, string &b, int m, int n){
	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
		int res = 0;

	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			if(a[i - 1] == b[j - 1]) { 
				dp[i][j] = 1 + dp[i - 1][j - 1];
				res = max(res, dp[i][j]);
			}
			else dp[i][j] = 0;
		}
	}
	return res;
}

int main(){
	string a = "OldSite:GeeksforGeeks.org";
	string b = "NewSite:GeeksQuiz.com";
	cout << getLongestSubstr(a, b, a.size(), b.size()) << endl;
	return 0;
} 