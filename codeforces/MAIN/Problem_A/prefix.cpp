class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string, int>map;
        int count = 0;
        string index;
        for(int i = 0; i < strs.size(); ++i){
            string s = strs[i];
            for(int i = 1; i <= s.size(); ++i){
                string str = s.substr(0,i);
                map[str]++;
            }
        }
        for(auto i : map){
            if(i.second >= count){
                count = i.second ;
                index = i.first;
            } 
        }
        return count >= strs.size() ? index : "";
    }
};