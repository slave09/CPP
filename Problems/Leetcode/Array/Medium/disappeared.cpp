class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums){
       
        vector<int>missing_number;
        
        for(int i = 0; i < nums.size(); ++i){
            
            if(nums[i] == i + 1) continue;
            
            while(nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }
        
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] != i + 1) missing_number.push_back(i + 1);
        
        return missing_number;
    }
};