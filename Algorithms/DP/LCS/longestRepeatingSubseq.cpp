/*
	# Longest Repeating subsequence 
	* return length of the longest subsequence in the string which is repeated in the string.

	* Take 2 same string and try to find longest common subsequence avoiding the same index

*/


#include<bits/stdc++.h>
using namespace std;


int getLongestRepeatingSubSeq(vector<vector<int>>&dp, string s, int m, int n){
	if(m == 0 || n == 0) return 0;
	if(dp[m][n] != -1) return dp[m][n];
	if(m != n && s[m - 1] == s[n - 1]) return dp[m][n] = 1 + getLongestRepeatingSubSeq(dp, s, m - 1, n - 1);
	return dp[m][n] = max(getLongestRepeatingSubSeq(dp, s, m - 1, n), getLongestRepeatingSubSeq(dp, s, m, n - 1));
}


int main(){
	string str = "AABEBCDD";
	vector<vector<int>>dp(str.size() + 1, vector<int>(str.size() + 1, -1));
	cout << "Length of Longest Repeating Subsequence : " << getLongestRepeatingSubSeq(dp, str, str.size(), str.size()) << endl;
	return 0;
}