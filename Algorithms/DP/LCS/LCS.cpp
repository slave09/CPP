/*

 # Longest Common SUbsequence Length : 

 a b c d e f g r e u w 
 r u c f h r w e r r w

  * if at i both the elements of string is same move to next element in both the strings
  * else there are two options
    -> move to the next element in str1 and stay at same element in str2
    -> move to the next element in str2 and stay at same element in str1
    -> since we need maximum : Take max of the above 2 cases.
*/


class Solution {
public:

    // Recursion + Memoization

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return getLongestSubsequenceLen(dp, text1, text2, text1.size(), text2.size());
    }

    int getLongestSubsequenceLen(vector<vector<int>>&dp, string &a, string &b, int m, int n){
        if(m == 0 || n == 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        if(a[m - 1] == b[n - 1]) return dp[m][n] = 1 + getLongestSubsequenceLen(dp, a, b, m - 1, n - 1);
        return dp[m][n] = max(getLongestSubsequenceLen(dp, a, b, m - 1, n),getLongestSubsequenceLen(dp, a, b, m, n - 1));
    }

    
    // Iterative 

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        
        for(int index = 0; index <= text1.size(); ++index) dp[index][0] = 0;
        for(int index = 0; index <= text2.size(); ++index) dp[0][index] = 0;

        for(int i = 1; i <= text1.size(); ++i){
            for(int j = 1; j <= text2.size(); ++j){
                if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[text1.size()][text2.size()];
    }

 };




/*

    # Print Longest Conmmon Subsequence
    - Traverse the matrix from the bottom end 
    - if the row and col is same include that letter in the and and move diagonally up
    - if row and col is not same move up or down where there is maximum value
    - the subsequence is taken in reverse order therefore reverse the result string

*/

string printSubSeq(vector<vector<int>>&dp, string a, string b){
    int n = a.size();
    int m = b.size();
    string s = "";

    while(n > 0 && m > 0){
        if(a[n - 1] == b[m - 1]){
            s += a[n - 1];
            n--;m--;
        }
        else if(dp[n-1][m] > dp[n][m-1]) n--;
        else m--;
    }
    reverse(s.begin(), s.end());
    return s;
}