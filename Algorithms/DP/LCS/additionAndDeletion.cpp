/*
    # Problem
    * Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

    * In one step, you can delete exactly one character in either string. 

    # Approach

    * Only deletion of those characters are needed that are not in the lcs of both the strings
*/

class Solution {
    int getLongestSubSeqLen(string a, string b){
        vector<vector<int>>dp(a.size() + 1, vector<int>(b.size() + 1, 0));
        for(int i = 1; i <= a.size(); ++i){
            for(int j = 1; j <= b.size(); ++j){
                if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[a.size()][b.size()];
    }
public:
    int minDistance(string word1, string word2) {
        int subSeqLen = getLongestSubSeqLen(word1, word2);
        return (word1.size() - subSeqLen) + (word2.size() - subSeqLen);
    }
};