class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int addUp = 0, total_sum = (nums.size()-1)*nums.size()/2;
        for(auto num : nums) addUp += num;
        return (total_sum - addUp);
    }
};