class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        
        vector<int>nums_copy = nums;
        
        sort(nums_copy.begin(), nums_copy.end());
        if(nums_copy == nums) return 0;
        
        int size = nums.size() - 1;
        
        int first_position = INT_MAX;
        int last_position  = INT_MIN;
        
        for(int i = 0, j = size; i <= size; ++i, j--){
            if(nums[i] != nums_copy[i]) 
                first_position = min(first_position, i);
            if(nums[j] != nums_copy[j])
                last_position = max(last_position, j);
        }
        
        
        return last_position - first_position + 1;
    }
};