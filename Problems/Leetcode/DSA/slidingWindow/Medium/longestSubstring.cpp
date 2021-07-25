class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        set<char>set;
        int index = 0, maxLen = 0;
        
        while(index < s.size()){
            
            int idx = index;
            int len = 0;
            
            while(idx < s.size()){
                if(set.find(s[idx]) == set.end()){
                    len++;
                    set.insert(s[idx]);
                    idx ++;
                }
                else {
                    idx++;
                    set.clear();
                    break;
                    
                }
                
            }
            
            maxLen = max(maxLen, len);
            index ++;
            
        }
        return maxLen;
    }
};