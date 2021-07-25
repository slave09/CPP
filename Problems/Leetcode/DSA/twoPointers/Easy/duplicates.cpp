class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>num;
        for(auto n: nums) num.insert(n);
        int index = 0;
        for(auto s:num)
            nums[index++] = s;
        return num.size();
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return 0;
        int index_pointer = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != nums[index_pointer]){
                index_pointer ++;
                nums[index_pointer] = nums[i];
            }
        }
        return index_pointer + 1;
    }
};

