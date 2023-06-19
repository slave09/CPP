/*
 
# Problem 

ShortestCommon SuperSequence

given two sequences X and Y, the LCS problem seeks to find a sequence Z that is a supersequence of both X and Y, and has the maximum possible length among all such supersequences. The length of the LCS is defined as the number of elements in Z.

* For example, let's say we have two sequences:
  X: ABCBDAB
  Y: BDCAB

* A possible common supersequence would be Z: ABCBDCAB, which contains all the elements of X and Y. The length of this LCS is 8.

# Approach

* Obtain LCS
* constructs the shortest common supersequence by iterating through each character in the LCS. 
* append all characters from str1 and str2 until the current LCS character is found, ensuring that all characters from both strings are included in the result. Finally, append any remaining characters from str1 and str2 that were not part of the LCS.

*/


class Solution {
public:

  string getLongestCommonSubSeq(string &a, string &b){
    string s = "";
    int n = a.size();
    int m = b.size();
    
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= m; ++j){
        if(a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    while(n > 0 && m > 0){
      if(a[n - 1] == b[m - 1]){
        s += a[n - 1];
        n--;m--;
      }
      else if(dp[n - 1][m] > dp[n][m - 1]) n --;
      else m--;
    }
    
    reverse(s.begin(), s.end());
    
    return s;
  }

  string shortestCommonSupersequence(string str1, string str2) {
    string subSeq = getLongestCommonSubSeq(str1, str2);
    int i = 0; int j = 0;
    string res = "";
    for(auto c : subSeq){
      while(i < str1.size() && str1[i] != c) res += str1[i++];
      while(j < str2.size() && str2[j] != c) res += str2[j++];
      res += c; i++; j++;
    }
    return res + str1.substr(i, str1.size() - i) + str2.substr(j, str2.size() - j);
  }
};