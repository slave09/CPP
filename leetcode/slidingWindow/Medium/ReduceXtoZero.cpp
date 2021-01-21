class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target =  -x;
        
        for(auto num : nums) target += num;
        
        if(target == 0) return nums.size();
        if(target < 0) return -1;
        
        int front = 0, addUp = 0, subArrLen = -1;
        
        for(auto n = 0; n < nums.size(); ++n){
            if(addUp < target) addUp += nums[n];
            while(addUp >= target){ 
                if(addUp == target) subArrLen = max(subArrLen, n - front + 1);
                addUp -= nums[front++];
            }
        }
        return subArrLen == -1 ? -1 : nums.size() - subArrLen; 
    }
};