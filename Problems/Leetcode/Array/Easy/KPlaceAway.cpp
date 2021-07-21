class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        int last_index = -1;
        
        for(int num = 0; num < nums.size(); ++num){
            if(nums[num] == 1){
                if(last_index != -1 && num - last_index - 1 < k) return false;
                else last_index = num;
            }
        }
        return true;
    }
};