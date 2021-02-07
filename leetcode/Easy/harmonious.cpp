class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        
        map<int,int> count;
        
        for(auto i : nums) count[i]++;

        if(count.size() == 1) return 0;
        
        int maxSubArrLen = 0, last = INT_MIN, lastCount = -1;
        
        for(auto num : count){
            if(last != INT_MIN && num.first - last <= 1)
                maxSubArrLen = max(maxSubArrLen, num.second + lastCount);
            last = num.first;
            lastCount = num.second;
        }
        return maxSubArrLen;
    }
};