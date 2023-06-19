class Solution {
    unordered_map<string,int>dp;
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        if(dp.find(s1+s2) != dp.end()) return dp[s1+s2];
        int size = s1.size();
        bool flag = false;
        for(int index = 1; index < size; ++index){
            bool noSwap = isScramble(s1.substr(0, index), s2.substr(0, index)) 
            && isScramble(s1.substr(index), s2.substr(index));
            bool withSwap = isScramble(s1.substr(0, index), s2.substr(size - index)) && 
            isScramble(s1.substr(index), s2.substr(0, size - index));
            if(noSwap || withSwap) {
                flag = true;
                break;
            };
        }
        return dp[s1+s2] = flag;
    }
};