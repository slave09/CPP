class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string>result;
        map<int, string>FizzBuzzHash;
        
        FizzBuzzHash.insert({3, "Fizz"});
        FizzBuzzHash.insert({5, "Buzz"});
        
        for(int num = 1; num <= n; ++num){
            
            string ans_str = "";
            
            for(auto hash : FizzBuzzHash)
                if(num % hash.first == 0) 
                    ans_str += hash.second;
            
            if(ans_str == "") ans_str += to_string(num);
            
            result.push_back(ans_str);
            
        }
        
        return result;
    }
};
