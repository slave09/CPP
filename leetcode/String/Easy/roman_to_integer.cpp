class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>symbol_value;
        
        symbol_value.insert({'I', 1});
        symbol_value.insert({'V', 5});
        symbol_value.insert({'X', 10});
        symbol_value.insert({'L', 50});
        symbol_value.insert({'C', 100});
        symbol_value.insert({'D', 500});
        symbol_value.insert({'M', 1000});
        
        int last_processed_val = 0;
        int curr_integer_val = 0;
        
        for(int curr = s.size() - 1; curr >= 0; --curr){
            if(last_processed_val <= symbol_value[s[curr]])
                curr_integer_val += symbol_value[s[curr]];
            else curr_integer_val -= symbol_value[s[curr]];
            last_processed_val = symbol_value[s[curr]];
        }
        
        return curr_integer_val;
        
    }
};