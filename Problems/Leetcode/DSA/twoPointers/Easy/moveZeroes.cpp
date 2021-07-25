class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int next = 0;
        for(int i = 0; i < size; ++i){
            if(nums[i] != 0)
                nums[next++] = nums[i];
        }
        for(int i = next; i < size; ++i){
            nums[i] = 0;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, last = 0; i < nums.size(); ++i){
            if(nums[i] != 0) 
                swap(nums[last++],nums[i]);
        }        
    }
};